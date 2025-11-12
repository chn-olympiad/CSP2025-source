#include <bits/stdc++.h>
using namespace std;

struct dl
{
	int bh,u,v,w;
}a[1100005];

int c[15];
bool vis[15];	
int f[11005];
int n,m,k;

int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool cmp(dl x,dl y)
{
	return x.w < y.w;
}

void kruscal()
{
	sort(a + 1,a + m + 1,cmp);
	long long ans = 0;
	int cnt = 0;
	for(int i = 1;i <= m;i++)
	{
		if(cnt == n - 1) break;
		int x = a[i].u,y = a[i].v;
		x = find(x),y = find(y);
		if(x != y)
		{
			f[x] = y;
			vis[a[i].bh] = 1;
			ans += a[i].w;
		}
	}
	for(int i = 1;i <= k;i++)
	{
		if(vis[i]) ans += c[i];
	}
	cout << ans;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n + k;i++) f[i] = i;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}	
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++)
		{
			int x;
			scanf("%d",&x);
			m++;
			a[m].bh = i;
			a[m].u = n + i;
			a[m].v = j;
			a[m].w = x;
		}
	}
	n += k;
	kruscal();
	return 0;
} 
