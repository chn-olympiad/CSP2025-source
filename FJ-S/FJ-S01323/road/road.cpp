#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 10005, M = 1e6+5;
int n, m, k;
long long res;
struct segment
{
	int u, v, w;
} e[M];

int p[N];
int find(int x)
{
	if(x != p[x]) return find(p[x]);
	return x;
}

void ku()
{
	sort(e + 1, e + m + 1, [](segment a, segment b)
	{
		return a.w < b.w;
	});
	rep(i, 1, n) p[i] = i;
	rep(i, 1, m)
	{
		int a = e[i].u, b = e[i].v, c = e[i].w;
		if(find(a) == find(b)) continue;
		p[find(a)] = find(b);
		res += 1ll * c;
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int a, b, c;
	rep(i, 1, m)
	{
		scanf("%d%d%d", &a, &b, &c);
		e[i] = {a, b, c};
	}
	ku();
	printf("%lld", res);
	return 0;
}
