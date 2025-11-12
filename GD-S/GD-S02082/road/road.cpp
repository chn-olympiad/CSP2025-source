#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=2e6+5,inf=1e9+7;
int n,m,k;
int c[15],a[15][N],f[N+15];
map<int,map<int,int> >bz;
int cnt=0;
struct node{
	int x,y,z;
}g[M*2];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int find(int x)
{
	if(f[x]!=x)return f[x]=find(f[x]);
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[++cnt].x=u;
		g[cnt].y=v;
		g[cnt].z=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			g[++cnt].x=i+n;
			g[cnt].y=j;
			g[cnt].z=a[i][j];
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	sort(g+1,g+1+cnt,cmp);
	int ans=0,tn=n,tot=0;
	for(int i=1;i<=cnt;i++)
	{
		int x=g[i].x,y=g[i].y,z=g[i].z;
		int xx=find(x);
		int yy=find(y);
		if(xx!=yy)
		{
			tot++;
			f[xx]=yy;
			ans+=z;
	//		cout<<x<<" "<<y<<" "<<z<<endl;
			if(x>n)
			{
				if(!bz[x][0])tn++;
				bz[x][++bz[x][0]]=i;
			}
			if(y>n)
			{
				if(!bz[y][0])tn++;
				bz[y][++bz[y][0]]=i;
			}
			if(tot==tn-1)break;
		}
	}
	for(int i=n+1;i<=n+k;i++)
	{
	//	cout<<bz[i][0]<<" ";
		if(bz[i][0]==1)
		{
			ans-=g[bz[i][1]].z;
		}
	}
	cout<<ans;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/
