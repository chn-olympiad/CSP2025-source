#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
#define N 5001
using namespace std;
int n,a[N],f[N][N],sum[N],maxn[N],ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		maxn[i]=max(maxn[i-1],a[i]);
	}
	sort(a,a+n);
	
	for(int i=1;i<=n;i++) 
	{
		f[i][2]=(f[i-1][2]+(sum[i]>maxn[i]*2))%MOD;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=3;j<=n;j++)
		{
			for(int l=i;l<=i+j-2;l++)
			{
				for(int p=2;p<=j;p++)
				{
					f[i][j]=(f[l][p]+(sum[i]>maxn[i]*2))%MOD;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			ans=(f[i][j]+ans)%MOD;
		}
	}
	cout<<ans;
	return 0;
} 
