#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[5010][5010],a[5010],mi[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	mi[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		mi[i]=mi[i-1]*2%mod;
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];i++)
	{
		f[1][i]=1;
	}
	for(int i=a[1];i<=a[n];i++)
	{
		f[1][i]=0;
	}
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=a[n];j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=a[i])
			{
				f[i][j]+=f[i-1][j-a[i]];
				f[i][j]%=mod;
			}
			else
			{
				f[i][j]+=mi[i-1];
				f[i][j]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=2;i<n;i++)
	{
		ans+=f[i][a[i+1]];
		ans%=mod;
	}
	printf("%d",ans);
	return 0;
}
