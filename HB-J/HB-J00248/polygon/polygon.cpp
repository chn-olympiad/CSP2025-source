#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxn,ans;
long long k,h;
void dfs(int last,int he,int maxb,int x)
{
	if(x>=3 && he>maxb*2)
	{
		ans++;
		ans%=998244353;
	}
	for(int i=last+1;i<=n;i++)
	{
		dfs(i,he+a[i],max(maxb,a[i]),x+1);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn==1)
	{
		for(int i=3;i<=n;i++)
		{
			k=1,h=1;
			for(int j=n;j>=n-i+1;j--)
			{
				k*=j;
				k/=h;
				h++;
				k%=998244353;
			}
			ans=(ans+k)%998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
