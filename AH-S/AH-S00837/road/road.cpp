#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,m,k,fa[10010],g[15],cnt;long long s;
map<int,bool>f;
int bcj(int i)
{
	if(fa[i]!=i)
	{
		return fa[i]=bcj(fa[i]);
	}
	return i;
}
struct r
{
	int a,b,w,c;
}a[N];
bool cmp(r a,r b)
{
	return a.w<b.w;
}
bool check()
{
	for(int i=1;i<n;i++)
	{
		if(bcj(i)!=bcj(i+1))
		return 0;
	}
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,w;i<=m;i++)
	{
		cin>>x>>y>>w;
		a[++cnt]={x,y,w,0};
	}
	for(int i=1,y;i<=k;i++)
	{
		cin>>g[i];
		for(int j=1;j<=n;j++)
		{
			cin>>y;
			a[++cnt]={i+n,j,y+g[i],i+n};
		}
	}
	for(int i=1;i<=n+k;i++)
	{
		fa[i]=i;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int x=bcj(a[i].a),y=bcj(a[i].b);
		if(x==y)continue;
		fa[x]=y;
		s+=a[i].w;
		if(a[i].c!=0)
		{
			if(f[a[i].c]==1)s-=g[a[i].c-n];
			f[a[i].c]=1;
		}
		if(check())break;
	}
	cout<<s;
	return 0;
}
