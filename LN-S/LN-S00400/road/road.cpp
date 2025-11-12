#include <bits/stdc++.h>

using namespace std;

struct Node{
	int a,b,c;
	bool operator < (const Node &a) const
	{
		return c < a.c;
	}
}a[100010];

	int n,m,k,ans = 0;
int p[100010];

int find(int a)
{
	if (p[a] != a) p[a] = find(p[a]);
	return p[a];
}

void klstra()
{
	for (int i = 1; i <= m; i ++ )
	{
		int pa = find(a[i].a), pb = find(a[i].b);
		if (pa != pb)
		{
			p[pa] = pb;
			ans += a[i].c;
		}
	}
}

int main ()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int x,b,c;
		cin >> x >> b >> c;
		a[i] = {x, b, c};
	}
	sort(a+1,a+n+1);
	klstra();
	cout << ans;
}
