#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxm=1e6+6;
struct rec
{
	int x,y,z;
}t[maxm];
int n,m,k,cnt,ans;
int c[15],a[15][maxn],fa[maxn];
int g[1003][1003];
int getfa(int x)
{
	if (x==fa[x]) return fa[x];
	return fa[x]=getfa(fa[x]);
}
bool cmp(rec a,rec b)
{
	return a.z<b.z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(g,0x3f3f3f,sizeof(g));
	cin>>n>>m>>k;
	for (int i=1;i<=m;++i) 
	{
		int x,y,z;
		cin>>x>>y>>z;
		if (x>y) swap(x,y);
		g[x][y]=z;	
	}
	for (int i=1;i<=k;++i) cin>>c[i];
	for (int i=1;i<=k;++i)
	{
		for (int j=1;j<=n;++j)
		{
			cin>>a[i][j];
		}
	}
	for (int i=1;i<=n;++i)
	{
		for (int j=i+1;j<=n;++j)
		{
			for (int p=1;p<=k;++p)
			{
				int z=c[p]+a[p][i]+a[p][j];
				g[i][j]=min(g[i][j],z);
			}
		}
	}
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1;i<=n;++i)
	{
		for (int j=i+1;j<=n;++j)
		{
			t[++cnt].x=i,t[cnt].y=j;
			t[cnt].z=g[i][j];
		}
	}
	sort(t+1,t+cnt+1,cmp);
	//for (int i=1;i<=n;++i) cout<<t[i].z<<' ';
	for (int i=1;i<n;++i)
	{
		int x=t[i].x;
		int y=t[i].y;
		//cout<<x<<' '<<y;
		int fx=getfa(x);
		int fy=getfa(y);
		//cout<<fx<<' '<<fy<<' ';
		if (fx==fy) continue;
		fa[fx]=fy;
		ans+=t[i].z;
		//cout<<ans<<' ';
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 
8 2 4 100
1 3 2 4
*/
