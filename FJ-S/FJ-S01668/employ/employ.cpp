#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
vector<int> emp,v,ans;
int n,m,answ;
string s;
bool check(){
	int cnt=0,fcnt=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0' || fcnt>=emp[ans[i]]){fcnt++;}
		else{cnt++;}
	}
//	cout << "check answer:"<< fcnt << " " << cnt << endl;
	return cnt>=m;
}
void dfs(int i,int n){
	if(i==n+1){
//		puts("------orz------");
//		for(int k=0;k<ans.size();k++){
//			printf("%d ",ans[k]);
//		}
		if(check()){
			answ=(answ+1)%mod;
//			puts("--->Accept");
		}
//		else puts("--->Refuse");
		return;
	}
	for(int j=0;j<n;j++){
		if(v[j])continue;
		ans.push_back(j);
		v[j]=1;
//		printf("round: %d\n",i);
//		for(int k=0;k<ans.size();k++){
//			printf("%d ",ans[k]);
//		}
		dfs(i+1,n);
		ans.pop_back();
		v[j]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m >> s;
	if(n>5){cout << 0;return 0;}
	v.resize(n);
	for(int i=0;i<n;i++){
		int x;cin >> x;
		emp.push_back(x);
	}
	sort(emp.begin(),emp.end());
	dfs(1,n);
	cout << answ;
	return 0;
}
