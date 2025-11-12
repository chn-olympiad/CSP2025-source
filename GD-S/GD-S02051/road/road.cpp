#include <bits/stdc++.h>
using namespace std;
#define int long long

int read()
{
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2e4+10;
struct node
{
	int u,v,w;
};
vector<node>e;
int fa[N];
int find(int x)
{
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
vector<node>a;
vector<node>b;
int cc[20][N];
int d[N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	int xu=n+1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e.push_back({u,v,w});
	}
	bool flag=true;
	int r=e.size();
	for(int i=1;i<=k;i++)
	{
		int c=read();
		if(c!=0)flag=false;
		d[i]=c;
		for(int j=1;j<=n;j++)
		{
			int x=read();
			cc[i][j]=x;
			a.push_back({n+i,j,x+c});
		}
	}
	int ans=0;
	for(int i=1;i<=n+1;i++)fa[i]=i;
	sort(e.begin(),e.end(),cmp);
	for(int i=0;i<r;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ans+=w;
		}
	}
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	if(flag)
	{
		for(auto k:a)e.push_back(k);
		sort(e.begin(),e.end(),cmp);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		int res=0;
		for(int i=0;i<e.size();i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=find(u),fv=find(v);
			if(fu!=fv)
			{
				fa[fu]=fv;
				res+=w;
			}
		}
		//cout<<ans<<" "<<res<<"\n";
		cout<<min(ans,res);
	}
	else
	{
		ans=1e18;
		for(int i=0;i<=(1<<k);i++)
		{
			int rnt=0;
			for(int i=1;i<=n+1;i++)fa[i]=i;	
			b.clear();
			for(auto k:e)b.push_back(k);
			for(int j=0;j<k;j++)
			{
				if((i>>j)&1)
				{
					rnt+=d[j+1];
					for(int u=1;u<=n;u++)
					{
						b.push_back({n+1,u,cc[j+1][u]});
					}
				}
			}
			sort(b.begin(),b.end(),cmp);
			int dnt=0;
			for(int i=0;i<b.size();i++)
			{
				int x=b[i].u,y=b[i].v,z=b[i].w;
				int fx=find(x),fy=find(y);
				if(fx!=fy)
				{
					dnt++;
					fa[fx]=fy;
					rnt+=z;
				}
				if(dnt>=n+20)break;
			}
			ans=min(ans,rnt);
		}
		cout<<ans;
	}
	return 0;
}
