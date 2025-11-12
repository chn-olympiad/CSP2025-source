#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[10010];
struct node{
	int val;
	int mar;
}a[10010][10010];
int idx;
int c[13];
int find(int l)
{
	if(l==fa[l])return l;
	return fa[l]=find(fa[l]);
}
int dis[10010],rec[10010];
int kruscal(int be,int w,int con)
{
	if(con>n)return w;
	for(int j=1;j<=n+k;j++)
	{
		int nxt,minn=0xffffff,tmp;
		if(a[be][j].mar)
		{
			tmp=a[be][j].val+c[a[be][j].mar];
		}
		if(tmp<minn&&!rec[j])
		{
			minn=tmp;
			nxt=j;
		}
		rec[nxt]=1;
		if(nxt<=n)con++;
		int f1=fa[be],f2=fa[nxt];
		if(f1!=f2)
		{
			fa[f1]=f2;
			if(a[be][j].mar)
			{
				w+=c[a[be][j].mar];
			}
			w+=a[be][nxt].val;
			kruscal(nxt,w,con);
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j].val=0xffffff;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v].val=w;
		a[v][u].val=w;
		a[u][v].mar=0;
		a[v][u].mar=0;
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[n+i][j].val=w;
			a[j][n+i].val=w;
			a[n+i][j].mar=i;
			a[j][n+i].mar=i;
			if(w!=0||c[i]!=0)
			{
				flag=0;
			}
		}
	}
	if(flag)
	{
		cout<<"0";
		return 0;
	}
	int minn=0xffffff;
	for(int i=1;i<=n;i++)
	{
		dis[i]=kruscal(i,0,0);
		minn=min(dis[i],minn);
    }
    cout<<minn;
	return 0;
} 
