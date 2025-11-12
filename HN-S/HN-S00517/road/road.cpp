#include<bits/stdc++.h>
#define int long long
using namespace std;
const signed cxk=1e6+91,cln=2e4+5;
int cnt,kk,mini,c[15],mkg;
signed fa[cln],n,m,k,a[15][cln];
bool vis[15];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void unio(int x,int y)
{
	if(find(x)!=find(y));
		fa[find(x)]=find(y);
}
struct ikun
{
	int x,y,w;
	friend bool operator<(const ikun&x,const ikun&y)
	{
		return x.w<y.w;
	}
}e[cxk],s[cxk],t[cxk];
inline void kruscal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y,w=e[i].w;
		if(find(x)!=find(y))
		{
			unio(x,y);
			s[++cnt]=e[i];
			mini+=w;
			mkg=max(mkg,w);
		}
		if(cnt==n-1)
			break;
	}
}
void kruscal2(int sum)
{
	int x78=n;
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	for(int i=1;i<=kk;i++)
	{
		t[i]=s[i];
		if(i>n)
			x78+=vis[i-n];
	}
	sort(t+1,t+kk+1);
	int kkk=0;
	for(int i=1;i<=kk;i++)
	{
		int x=t[i].x,y=t[i].y,w=t[i].w;
		if(find(x)!=find(y))
		{
			unio(x,y);
			sum+=w;
			kkk++;
		//	cout<<w<<" ";
		}
//		if(kkk==x78-1)
//			break;
	}
	mini=min(mini,sum);
	//cout<<"\n";
}
void dfs(int x,int y)
{
	if(x>k)
	{
		kk=cnt;
		for(int i=1;i<=k;i++)
			if(vis[i])
				for(int j=1;j<=n;j++)
					if(a[i][j]<=mkg||j==1)
						s[++kk]={n+i,j,a[i][j]};//¼ôÖ¦?
		kruscal2(y);
		return;
	}
	vis[x]=0;
	dfs(x+1,y);
	vis[x]=1;
	dfs(x+1,y+c[x]);
} 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].x>>e[i].y>>e[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	kruscal();
	dfs(1,0);
	cout<<mini;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
