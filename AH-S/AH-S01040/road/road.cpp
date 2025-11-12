#include<bits/stdc++.h>
using namespace std;
struct road
{
	long long u,v,w;
}t[114514];
long long ans=0;
bool cmp(road x,road y)
{
	return x.w<y.w;
}
long long fa[114514];
long long find(int x)
{
	while(fa[x]!=x)
		x=fa[x]=fa[fa[x]];
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		cin>>t[i].u>>t[i].v>>t[i].w;
	for(int i=1;i<=k;i++)
	{
		int pppppppp;
		cin>>pppppppp;
	}
	sort(t+1,t+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(t[i].u);
		int y=find(t[i].v);
		if(x==y)
			continue;
		else
		{
			ans+=t[i].w;
			fa[x]=y;
		}
	}
	cout<<ans<<endl;
	return 0;
}
