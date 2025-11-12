//GZ-S00496 贵阳市第三中学 马俊杰
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=3e6+10;
int fa[N];
struct node{
	long long u,v,w;
}a[N];
int fd(int x)
{
	if(fa[x]==x)return x;
	return fd(fa[x]);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		cin>>x;
	} 
	sort(a+1,a+1+m,cmp);
	int mn=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(fd(a[i].v)!=fd(a[i].u))
		{
			fa[a[i].v]=fd(a[i].u);
			mn+=a[i].w;
			cnt++;
		}
		if(cnt==n-1)break;
	}
	cout<<mn<<'\n';
	return 0;
}
