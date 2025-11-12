#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[1000001],t,ans;
int C(int n,int m)
{
	int l=1,ll=1;
	for(int i=n;i>n-m;i--) l*=i,l%=mod;
	for(int i=2;i<=m;i++) ll*=i,ll%=mod;
	return l%mod/ll%mod;
}
void dfs(int w,int maxn,int k,int sum,int l)
{
	if(k==l)
	{
		if(sum>2*maxn) ans++;
		return ;
	}
	if(w==n+1) return ;
	dfs(w+1,maxn,k,sum,l);
	dfs(w+1,max(maxn,a[w]),k+1,sum+a[w],l);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int p=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];	
		if(a[i]!=1) p=1;
	}
	if(p==0)
	{
		for(int i=3;i<=n;i++) ans+=C(n,i)%mod,ans%=mod;
		return cout<<ans,0;
	}
	if(n<=20) 
	{
		for(int i=3;i<=n;i++) dfs(1,0,0,0,i),ans%=mod;
		return cout<<ans,0;	
	}
	cout<<0;
	return 0;
 } 
