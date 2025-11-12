#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+1000,K=15;
int n,m,k,fa[N],tot=0,ans=0,val[K],c[K][N];
struct node
{
	int x,y,z;
}e1[N],ee[N],e[N];
bool cmp(node x,node y)
{
	return x.z<y.z;
}
int getfa(int x)
{
	if(x==fa[x])return fa[x];
	return (fa[x]=getfa(fa[x]));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e1[i].x>>e1[i].y>>e1[i].z;
	sort(e1+1,e1+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int fx=getfa(e1[i].x);
		int fy=getfa(e1[i].y);
		if(fx!=fy)
		{
			ee[++tot]=e1[i];
			fa[fx]=fy;
			ans+=e1[i].z;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		for(int j=1;j<=n;j++)
			cin>>c[i][j];
	}
	for(int i=1;i<(1ll<<k);i++)
	{
		int cnt=n,now=tot,res=0;
		for(int j=1;j<=tot;j++)
			e[j]=ee[j];
		for(int j=1;j<=k;j++)
		{
			if(i&(1ll<<(j-1)))
			{
				cnt++;
				res+=val[j];
				for(int p=1;p<=n;p++)
					e[++now]=(node){cnt,p,c[j][p]};
			}
		}
		sort(e+1,e+1+now,cmp);
		for(int j=1;j<=cnt;j++)
			fa[j]=j;
		for(int j=1;j<=now;j++)
		{
			int fx=getfa(e[j].x),fy=getfa(e[j].y);
			if(fx!=fy)
			{
				res+=e[j].z;
				fa[fx]=fy;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
