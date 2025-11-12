#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+1,M=1e5+1;
struct node{
	int x,y,w;
}e[N];
int n,m,k,fa[N],c[N],a[11][M],ans,sum,minn,flag=1;
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	while(x!=fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void kruskal()
{
	ans=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1,cnt=1,x,y;cnt<n;++i)
	{
		x=find(e[i].x),y=find(e[i].y);
		if(x!=y)ans+=e[i].w,fa[y]=x,++cnt;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>e[i].x>>e[i].y>>e[i].w;
	}
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		if(c[i])flag=0;
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	if(flag)
	{
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)e[++m].x=n+i,e[m].y=j,e[m].w=a[i][j];
		}
		n+=k;
		for(int i=1;i<=n;++i)fa[i]=i;
		kruskal();
		cout<<ans;
	}else
	{
		for(int i=1;i<=n;++i)fa[i]=i;
		kruskal();
		minn=ans;
		int nn=n;
		for(int i=1,tmp;i<=k;++i)
		{
			tmp=m;
			++n;
			for(int j=1;j<=nn;++j)e[++m].x=n,e[m].y=j,e[m].w=a[i][j];
			for(int j=1;j<=n;++j)fa[j]=j;
			kruskal();
			if(ans+sum+c[i]<minn)
			{
				sum+=c[i];
				minn=ans+sum;
			}else m=tmp,--n;
		}
		cout<<minn;
	}
}
