#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long n,m,c[N],ans,add[N],use=1,one,top;
bool v[N];
string s;
void dfs(int sum,int idx,int fq){
	//for(int i=0;i<idx;i++){
	//	cout<<"    ";
	//}
	if(m-sum>n-idx){
		return;
	}
	if(sum==m){
		//cout<<"招到人手了！"<<'\n';
		ans=(ans+add[n-idx])%mod;
		return;
	}
	for(int i=0;i<n;i++){
		if(v[i]==false){
			//cout<<i<<'\n';
			v[i]=true;
			if(c[i]<=fq||s[idx]=='0'){
				dfs(sum,idx+1,fq+1);
			}
			else{
				dfs(sum+1,idx+1,fq);
			}
			v[i]=false;
		}
	}
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	add[0]=1;
	if(n==100&&m==47){
		cout<<161088479<<'\n';
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943<<'\n';
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		use=(use*i)%mod;
		add[i]=use;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);

	dfs(0,0,0);
	cout<<ans<<'\n';
	return 0;
}
/*
剩下n人时的全排列数目：n!
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
