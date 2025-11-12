#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],p[5005],f[5005],ans,x,y,z;
const int mod=998244353;
void dfs(int idx,int d,int maxi)
{
	if(idx==d+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i])
			{
				sum+=a[i];
			}
		}
		if(sum>2*a[maxi])
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=maxi+1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			dfs(idx+1,d,i);
			f[i]=0;
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>=5)
	{
		for(int i=3;i<=n;i++)
		{
			x=1,y=1;
			for(int j=1;j<=i;j++)
			{
				x*=(n+j-1-i+1);
				y*=i-j+1;
				if(x%y==0)
				{
					x/=y;
					y=1;
				}
			}
			ans=(ans+x)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		dfs(1,i,0);
	}
	cout<<ans%mod;
	return 0;
}
