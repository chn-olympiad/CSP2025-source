#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[10005],c,ans;
struct node{
	int u,v,w;
}a[11000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=10000;i++) f[i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int d=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		++n;
		for(int i=1;i<=d;i++)
		{
			++m;
			cin>>a[m].w;
			a[m].u=n;
			a[m].v=i;
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)==find(a[i].v)) continue;
		ans+=a[i].w;
		f[find(a[i].u)]=find(a[i].v);
	}
	cout<<ans;
}
