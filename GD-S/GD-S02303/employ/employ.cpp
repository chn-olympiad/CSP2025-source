#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,q,p,v[505];
string c;
long long f[300005][20];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int x,y=0;
	scanf("%d%d",&n,&m);
	cin>>c;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]=='0')
		{
			q=1;
			break;
		}
	}
	if(!q)
	{
		long long s=1;
		for(int i=1;i<=n;i++)s=(s*i)%mod;
		printf("%lld",s);
		return 0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	p=(1<<n);
	f[0][0]=1;
	for(int i=0;i<p-1;i++)
	{
		y=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))y++;
		for(int j=1;j<=n;j++)
			if(!(i&(1<<(j-1))))
			{
				for(int u=0;u<=n;u++)
				{
					if(u>=v[j]||c[y]=='0')x=(i|(1<<(j-1))),f[x][u+1]=(f[x][u+1]+f[i][u])%mod;
					else x=(i|(1<<(j-1))),f[x][u]=(f[x][u]+f[i][u])%mod;
				}
			}
	}
//	for(int i=1;i<p;i++)
//	{
//		cout<<i<<':';
//		for(int j=0;j<=n;j++)cout<<f[i][j]<<' ';
//		cout<<'\n';
//	}
	long long s=0;
	for(int i=0;i<=n-m;i++)s=(s+f[p-1][i])%mod;
	printf("%lld",s);








  return 0;
}

