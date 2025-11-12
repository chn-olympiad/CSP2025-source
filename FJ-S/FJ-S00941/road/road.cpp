#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+5;
const int maxn=1e4+5;
int fa[maxm];
int n,m,k;
int get(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
int merge(int x,int y)
{
	fa[get(x)]=get(y);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
}
struct node
{
	int x,y,z;
}p[maxn];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y>>p[i].z;
	}
	int ans=0;
	init();
	for(int i=1;i<=m;i++)
	{
		int x=p[i].x,y=p[i].y,z=p[i].z;
		int fx=get(x),fy=get(y);
		if(fx!=fy)
		{ 
			merge(fx,fy);
			ans+=z;	
		}
	}
	
	cout<<ans;
	return 0;
 }

