#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],b[1000005],c[1000005],f[10005],ff[20][10005],e[20],g[20][10005],ma,sum=0,ffa,ffb;
int find(int x)
{
	if(f[x]==x)
	{
		return x;
	}
	f[x]=find(f[x]);
	return f[x];
}
int ffind(int x,int i)
{
	if(ff[i][x]==x)
	{
		return x;
	}
	ff[i][x]=ffind(ff[i][x],i);
	return ff[i][x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(c[i]>c[j])
			{
				int x=a[i],y=b[i],z=c[i];
				a[i]=a[j];
				b[i]=b[j];
				c[i]=c[j];
				a[j]=x;
				b[j]=y;
				c[j]=z;
			}
		}
	}
	g[0][0]=1e9;
	for(int i=1;i<=k;i++)
	{
		cin>>e[i];
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
			g[0][j]=1e9;
			g[i][0]=1e9;
			f[j]=j;
			ff[i][j]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(find(a[i])==find(b[i]))
		{
			continue;
		}
		ma=0;
		ffa=0;
		ffb=0;
		for(int j=1;j<=k;j++)
		{
			int fa=ffind(a[i],j),fb=ffind(b[i],j);
			if(c[i]>=g[j][fa]+g[j][fb]+e[j])
			{
				if(g[ma][ffa]+g[ma][ffb]+e[ma]>=g[j][fa]+g[j][fb]+e[j])
				{
					ma=j;
					ffa=fa;
					ffb=fb;
				}
			}
		}
		if(ma!=0)
		{
			sum+=e[ma]+g[ma][ffa]+g[ma][ffb];
			e[ma]=0;
			g[ma][a[i]]=0;
			g[ma][b[i]]=0;
		}
		else
		{
			sum+=c[i];
		}
		f[b[i]]=f[a[i]];
		for(int j=1;j<=k;j++)
		{
			if(g[j][ff[j][a[i]]]<=g[j][ff[j][b[i]]])
			{
				ff[j][b[i]]=ff[j][a[i]];
			}
			else
			{
				ff[j][a[i]]=ff[j][b[i]];
			}
		}
	}
	cout<<sum;
	return 0;
}
