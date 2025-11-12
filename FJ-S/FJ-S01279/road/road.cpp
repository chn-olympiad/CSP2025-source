#include <bits/stdc++.h>
using namespace std;
const int N=1e4+1;
int n,m,k,u,v,x[N],w,ans,a[N][N];
void work(int o,int h)
{
	if (h>n)
	{
		cout<<ans;
		return ;
	}
	int k,mi=0x3333333f;
	x[o]=-1;
	for (int i=1;i<=n;i++)
	{
		if (x[i]==-1)
		{
			continue;
		}
		x[i]=min(a[o][i],x[i]);
		if (mi>x[i]){
			mi=x[i];
			k=i;
		}
	}
	if (mi!=0x3333333f) ans+=mi;
	work(k,h+1);
} 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3333333333f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=min(w,a[v][u]);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		for (int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for (int j=1;j<=n;j++)
		{
			for (int l=j+1;l<=n;l++)
			{
				a[l][j]=a[j][l]=min(x[j]+x[l]+u,a[l][j]);
			}
		}
	}
	memset(x,0x3333333333f,sizeof(x));
	work(1,1);
	return 0;
}
