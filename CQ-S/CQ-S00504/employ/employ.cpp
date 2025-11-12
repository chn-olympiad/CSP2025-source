#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt[100100];
int ans=0;
vector<int> cnt1;
string str;
int ff[10010];
void dfs(int id){
	if(id>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(i-1>cnt[cnt1[i]]) continue;
			if(str[i-1]=='1') sum++;
		}
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(ff[i]==0){
			ff[i]=1;
			cnt1.push_back(i);
			dfs(id+1);
			cnt1.pop_back();
			ff[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>str;
	cnt1.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

