#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5010];
int v[5010];
int vis[5010];
void dfs(int k)
{
	if(k>=4)
	{
		int sum=0;
		for(int i=1;i<k;i++)
		{
			sum+=v[i];
		}
		if(sum>2*v[k-1])
		{
			// cout<<ans<<" "<<sum<<" "<<v[k-1]<<'\n';
			ans++;
			ans%=mod;
		}
	}
	if(k==n+1)
		return;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=v[k-1]&&vis[i]==0)
		{
			vis[i]=1;
			v[k]=a[i];
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}