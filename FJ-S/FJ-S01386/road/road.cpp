#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[1505][1505],f[1505],x,y,z,w=1e10,mi,s=0;
bool pd()
{
	bool g=true;
	for(int i=1;i<=n-k;i++)
	{
		if(f[i]>0) g=false;
	}
	return g;
}
void road()
{
	for(int i=2;i<=n;i++) f[i]=a[1][i];
	f[0]=w;
	f[1]=-1;
	for(int i=1;i<n;i++)
	{
		mi=0;
		for(int j=2;j<=n;j++) if(f[j]!=-1&&f[j]<=f[mi]) mi=j;
		s+=f[mi];
		if(mi>n-k)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[mi][j]>0&&a[mi][j]<w)
				{
					a[mi][j]-=a[mi][0];
					a[j][mi]-=a[mi][0];
				}
			}
		}
		f[mi]=-1;
		for(int j=1;j<=n;j++) if(a[mi][j]<f[j]) f[j]=a[mi][j];
		if(pd()==true)
		{
			cout<<s;
			break;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
		a[y][x]=z;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>z;
		a[n+i][0]=z;
		a[0][n+i]=z;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			a[n+i][j]=x+z;
			a[j][n+i]=x+z;
		}
	}
	n+=k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==0)
			{
				a[i][j]=w;
			}
		}
	}
	road();
	return 0;
}
