#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w;
	void init(int u,int v,int w)
	{
		this->u=u;
		this->v=v;
		this->w=w;
	}	
};
const int N=5e6+10;
node a[N];
int pos;
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int fa[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[++pos].init(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		int ww;
		cin>>ww;
		a[++pos].init(i*2+n-1,i*2+n,ww);
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[++pos].init(i*2+n-1,j,w);
			a[++pos].init(i*2+n,j,w);
		}
	}
	sort(a+1,a+pos+1,cmp);
	for(int i=1;i<=n+2*k;i++)fa[i]=i;
	int ans=0;
	for(int i=1;i<=pos;i++)
	{
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy)continue;
		if(fx>fy)swap(fx,fy);
		fa[fx]=fy;
		ans+=a[i].w;
	}
	cout<<ans<<endl;
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
