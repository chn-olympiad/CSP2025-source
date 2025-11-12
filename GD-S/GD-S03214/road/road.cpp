#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int u,v,w;
}a[1000006];
int fa[10004];
int cnt=0;
int ans=0;
bool cmp(Node c,Node d)
{
	return c.w<d.w;
}
bool check()
{
	for(int i=1;i<n;i++)
	{
		if(fa[i]!=fa[i+1])return false;
	}
	return true;
}
int find(int x)
{
	if(fa[x]==x)return fa[x];
	fa[x]=(find(fa[x]));
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(check())break;
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=a[i].w;
	}
	cout<<ans;
}
