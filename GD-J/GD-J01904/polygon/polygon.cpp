#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5025];
int vis[5025];
int tmp[5025];
int mod=998244353,cnt,n;
int f(int n)
{
	if(n==0) return 1;
	return (n*f(n-1)%mod)%mod;
}
void dfs(int k,int final,int pos)
{
	if(k==final)
	{
		int maxn=-1;
		int sum=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,tmp[i]),sum+=tmp[i];
		if(sum>2*maxn) cnt=(cnt+1)%mod;
		return ;
	}
	for(int i=pos+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			tmp[k+1]=a[i];
			dfs(k+1,final,i);
			vis[i]=0;
		}
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxn=-1;
	for(int i=1;i<=n;i++)
	 cin>>a[i],maxn=max(maxn,a[i]);
	if(maxn==1)
	{
		int ans=0;
		for(int i=3;i<=n;i++)
		 ans=(ans+f(n)/f(i)/f(n-i))%mod;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=3;i<=n;i++) dfs(0,i,0);
	cout<<cnt<<endl;
	return 0;
 } 
