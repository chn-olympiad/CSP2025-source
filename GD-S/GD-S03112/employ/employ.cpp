#include<bits/stdc++.h>
using namespace std;
const int N=20,M=(1<<18)+10,mod=998244353;
int n,m,a[N],c[N],f[M][N],g[M][N],cnt[M];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		char c;
		cin>>c;
		if(c=='1')a[i]=1;
	}
	for(int i=1; i<=n; i++)cin>>c[i];
	for(int i=1; i<(1<<n); i++)
		for(int j=1; j<=n; j++)
			if(i&(1<<j-1))cnt[i]++;
	f[0][0]=1;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<(1<<n); j++)
		{
			if(cnt[j]!=i)continue;
			for(int k=1; k<=n; k++)
			{
				if(j&(1<<k-1))
				{
					for(int l=0; l<=i; l++)
					{
						if(c[k]>i-l&&a[i]&&l)(g[j][l]+=f[j^(1<<k-1)][l-1])%=mod;
						if(c[k]<=i-l||!a[i])(g[j][l]+=f[j^(1<<k-1)][l])%=mod;
					}
				}
			}
		}
		for(int j=1; j<(1<<n); j++)
		{
			if(cnt[j]!=i)continue;
			for(int k=0; k<=i; k++)f[j][k]=g[j][k];
		}
	}
	int ans=0;
	for(int i=m; i<=n; i++)(ans+=f[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}
