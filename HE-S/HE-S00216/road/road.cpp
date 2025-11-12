#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=10905;
int n,m,k,f[N],c[N];
struct NO
{
	int u,v,w;
}a[N];
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(NO a,NO b)
{
	return a.w<b.w;
}
void solve1()
{
	int ans=0,cnt=0;
	for (int i=1;i<=m;i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
		f[a[i].u]=a[i].u;
		f[a[i].v]=a[i].v;
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		int fx=find(a[i].u);
		int fy=find(a[i].v);
		if (fx!=fy)
		{
			f[fx]=fy;
			ans+=a[i].w;
			cnt++;
		}
		if (cnt==n-1)
		{
			cout << ans;
			exit(0);
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	if (k==0)
	{
		solve1();
	}
	else
	{
		cout << rand();
	}
	return 0;
}
/*
5 6 0
1 2 5
2 4 3
2 3 2
2 5 10
1 3 1
3 4 4

*/
