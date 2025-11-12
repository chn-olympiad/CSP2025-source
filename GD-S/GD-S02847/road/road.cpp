#include<bits/stdc++.h>
using namespace std;

int n,m,k,esz,psz,c[15],a[15][10010];
bool vis[2010];
long long ans=1e18,sumx;
struct node{int x,y,w;}e[2000010],p[2000010];
bool cmp(node x,node y){return x.w<y.w;}
int fa[2000010];
void init(){for(int i=1;i<=psz;i++) fa[i]=i;}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){fa[find(x)]=find(y);}
void kruscal()
{
	init();
	sort(e+1,e+esz+1,cmp);
	int cnt=0;
	for(int i=1;i<=esz;i++)
	{
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if(find(x)==find(y)) continue;
		cnt++;sumx+=w;merge(x,y);
		if(cnt==psz-1) break;
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>p[i].x>>p[i].y>>p[i].w;
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k<=5)
	{
		for(int msk=0;msk<(1<<k);msk++)
		{
			for(int i=1;i<=m;i++) e[i]=p[i];
			esz=m;psz=n;sumx=0;
			for(int i=0;i<k;i++)
			{
				if(!(msk>>i)&1) continue;
				psz++;sumx+=c[i];
				for(int j=1;j<=n;j++) e[++esz]={psz,j,a[i][j]};
			}
			kruscal();
			ans=min(ans,sumx);
		}
		cout<<ans<<endl;
		return 0;
	}
	int tp=0;
	for(int msk=0;tp<10000000/m && tp<(1<<k);)
	{
		msk=rand()%(1<<k);
		if(vis[msk]) continue;
		vis[msk]=true;tp++;
		for(int i=1;i<=m;i++) e[i]=p[i];
		esz=m;psz=n;sumx=0;
		for(int i=0;i<k;i++)
		{
			if(!(msk>>i)&1) continue;
			psz++;sumx+=c[i];
			for(int j=1;j<=n;j++) e[++esz]={psz,j,a[i][j]};
		}
		kruscal();
		ans=min(ans,sumx);
	}
	cout<<ans<<endl;
	return 0;
}
