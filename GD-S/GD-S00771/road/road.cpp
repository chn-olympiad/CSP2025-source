#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot=0;
struct EDGE{
	int u,v,w;
}e[2000005];
void add(int u,int v,int w){e[++tot]={u,v,w};}
bool cmp(EDGE x,EDGE y){return x.w<y.w;}
int fa[1001005];
int _find(int x){return fa[x]==x?x:fa[x]=_find(fa[x]);}
bool join(int x,int y)
{
	int fx=_find(x),fy=_find(y);
	if(fx==fy)return false;
	fa[fx]=fy;
	return true;
}
void Kruscal()
{
	long long ans=0;
	sort(e+1,e+1+tot,cmp);
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=tot;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(join(u,v))
		{
	//		cout<<u<<" to "<<v<<" with "<<w<<endl;
			ans=ans+(long long)w;
		}
	}
	cout<<ans;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		add(0,n+i,c);
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			add(n+i,j,w);
		}
	}
	Kruscal();
	return 0;
}
