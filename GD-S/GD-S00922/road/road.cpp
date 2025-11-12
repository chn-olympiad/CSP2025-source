#include <bits/stdc++.h>
using namespace std;

struct st
{
	long long u, v, w;
};

bool cmp(st x, st y)
{
	return x.w < y.w;
}

const int N = 1e6 + 5;
long long n, m, k, u , v, w, c, cur = 0, ans = 0, f[N];
st l[N];

void build(long long k)
{
	for(int i = 1; i <= k; i ++)
	{
		f[i] = i;
	}
}

long long find(long long k)
{
	if(f[k] == k)
	{
		return k;
	}
	else
	{
		return find(f[k]);
	}
}

void init(long long x, long long y)
{
	f[x] = y;
	return;
}

long long minn(long long k)
{
	build(k);
	long long nn = k, sum = 0, cnt = 0;
	while(nn > 1)
	{
	//	cout << find(l[++cnt].u) << " " << find(l[cnt].v) << "\n";
		if(find(l[++cnt].u) != find(l[cnt].v))
		{
			nn --; 
			sum += l[cnt].w;
			init(l[cnt].u, l[cnt].v);
		}
	}	
//	cout << endl;
	return sum;
}
int main()
{
	#ifdef LOCAL
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++)
	{
		cin >> l[i].u >> l[i].v >> l[i].w;
	}
	cur = m;
	long long now = m;
	sort(l + 1, l + cur + 1, cmp);
	ans = minn(n); 
	for(int i = 1; i <= k; i ++)
	{
		now = cur;
		cin >> c;
		for(int j = 1; j <= n; j ++)
		{
			cin >> l[++cur].w;
			l[cur].u = j;
			l[cur].v = n + i;
		}
		sort(l + 1, l + cur + 1, cmp);
		ans = min(ans, c + minn(n + i));
	//	cout << c + minn(n + i) << "\n";
	}
	cout << ans;
}
