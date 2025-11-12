#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10001],c;
struct note{
	int u,v,w;
}e[1100001];
bool cmp(note i,note j)
{
	return i.w<j.w;
}
int Find(int x)
{
	while(x!=f[x])
		x=f[x];
	return x;
}
void Union(int a,int b)
{
	int fa=Find(a),fb=Find(b);
	f[fa]=fb;
}
void solve1()
{
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
		f[i]=i;
	int cnt=0;long long s=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)
		{
			cout<<s;
			return;
		}
		if(Find(e[i].u)!=Find(e[i].v))
			s=s+e[i].w,Union(e[i].u,e[i].v),cnt++;
	}
	cout<<s;
}
void solve2()
{
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		for(int j=1;j<=n;j++)
			m++,e[m].u=i,e[m].v=j,cin>>e[m].w;
	}
	solve1();
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	if(k==0)
		solve1();
	else
		solve2();
	return 0;
}
