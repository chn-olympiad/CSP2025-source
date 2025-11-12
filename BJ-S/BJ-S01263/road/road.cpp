#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=2e6+5;
struct node{
	int x,y;
	ll z;
	bool f;//f=0 is old  f=1 is new
}a[M];
int fa[N*2];
bool cmp(node n1,node n2)
{
	return n1.z<n2.z;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].f=0;
	}
	int nl=n;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		a[++m]={i,++n,x,1};
		for(int j=1;j<=nl;j++)
		{
			cin>>x;
			a[++m]={n,j,x,1};
		}
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a+1,a+m+1,cmp);
	ll ans=0;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		ll z=a[i].z;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			ans+=z;
			fa[fx]=fy;
			if(++cnt==n-1)
				break;
		}
	}
	cout<<ans;
	return 0;
}
