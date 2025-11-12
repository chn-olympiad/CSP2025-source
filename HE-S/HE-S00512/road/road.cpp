#include <bits/stdc++.h>
using namespace std;
const int N = 10010,M = 1000010;
//vector<int>G[N];
int c[15],b[15][N];
struct node
{
	int u,v,w;
	bool operator<(const node &l)const
	{
		return w<l.w;
	}
}a[M];
int f[N];
// min tree
int findzza(int x)
{
	if (x==f[x]) return x;
	return f[x]=findzza(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[i]={x,y,z};
	}
	sort(a+1,a+m+1);
	int fl=1;
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if (c[i]) fl=0;
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&b[i][j]);
			if (b[i][j]) fl=0;
		}
	}
	for (int i=1;i<=n;i++) f[i]=i;
	long long ans=0;
	for (int i=1;i<=m;i++)
	{
		int x=a[i].u,y=a[i].v,z=a[i].w;
		int e=findzza(x),d=findzza(y);
		if (e==d) continue;
		ans+=z;
		f[e]=d;
	}
	if (fl&&k!=0) printf("0");
	else printf("%lld",ans);
	return 0;
}
