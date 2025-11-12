#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,vis[2005],ans,s[2005],c[2005],sum;
string a;
void dfs(int x,int sum,int num){
	if(x>n){
		if(num>=m)ans=ans+1;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			vis[i]=1;
			if(sum<c[i]&&s[x-1]) dfs(x+1,sum,num+1);
			else dfs(x+1,sum+1,num);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<int(a.size());++i) s[i]=a[i]-'0',sum+=s[i];
	for(int i=1;i<=n;++i) cin>>c[i];
	if(sum<m) cout<<0,exit(0);
	if(sum==n){
		long long num=1;
		for(int i=2;i<=n;++i) num=(num*i)%MOD;
		cout<<num,exit(0);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
