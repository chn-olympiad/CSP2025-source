#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct PLAM
{
	int v;
	int num;
}a[10000][10000];
int kl[10000];
int b[15][10009];
int prim[15];
int d[10009];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,l,ans=0;
	cin>>n>>m>>l;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u]++;
		d[v]++;
		kl[u]++;
		kl[v]++;
		for(int j=1;j<=kl[u];j++)
		{
			if(j==kl[u])
			{
				a[u][j].num=w;
			}
			if(a[i][j].v==v)
			{
				a[u][j].num=min(a[u][j].num,w);
				break;
			}
		}
		a[u][kl[u]].v=v;
		for(int j=1;j<=kl[v];j++)
		{
			if(j==kl[v])
			{
				a[v][j].num=w;
			}
			if(a[i][j].v==v)
			{
				a[v][j].num=min(a[v][j].num,w);
				break;
			}
		}
		a[v][kl[v]].v=u;
	}
	for(int i=1;i<=l;i++)
	{
		cin>>prim[i];
		for(int j=1;j<=n;j++)
		cin>>b[i][j];
	}
	int U=1,V=a[1][1].v,W=1e9,T=0;
	for(int i=1;i<=n;i++)
	{
		W=a[i][1].num;
		if(d[i]>1 && d[a[i][1].v]>1)
		{
			T=1;
			U=i;
			W=a[i][1].num;
			V=a[i][1].v;
		}
		for(int j=1;j<=kl[i];j++)
		{
			if(d[i]>1 && d[a[i][1].v]>1)
			{
				
				if(a[i][j].num<W && W!=1e9)
				{
					d[i]--;
					d[V]--;
					V=a[i][j].v;
					W=a[i][j].num;
					a[i][T].num=1e9;
					a[i][T].v=-1;
					T=j;
					
					continue;
				}
				if(a[i][j].num>W && W!=1e9)
				{
					d[i]--;
					d[a[i][j].v]--;
					a[i][j].num=1e9;
					a[i][j].v=-1;
					
				}
			}
		}
		//cout<<i<<" "<<V<<"\n";
		//cout<<W<<"\n";
		if(W==a[i][1].num && V==i)
		continue;
		ans=ans+W;
	}
	cout<<ans;
	
	fclose(stdin);fclose(stdout);
	return 0;
}
