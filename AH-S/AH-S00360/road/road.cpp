#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans;
int fa[10001];
int find(int x)
{
	if(fa[x]==x) return x;
	return find(fa[x]);
}
struct node{
	int x,y,w;
}a[10001];
void uni(int x,int y)
{
	fa[y]=x;
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].x)!=find(a[i].y))
		{
			uni(a[i].x,a[i].y);
			ans+=a[i].w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1,x;j<=n+1;j++)
		{
			cin>>x;
		}
	}
	cout<<ans;
	return 0;
}
