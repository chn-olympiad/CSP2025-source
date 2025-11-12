#include <bits/stdc++.h>
using namespace std;
const int N = 100240;
struct node
{
	int x, v;
	node() {}
	node(int X, int V) : x(X), v(V) {}
	inline bool operator<(node b) const
	{
		return v == b.v ? x < b.x : v > b.v;
	}
	inline bool operator>(node b) const
	{
		return b < *this;
	}
};
struct MyClub
{
	int v[3];
	inline bool operator<(MyClub b) const
	{
		int x = 0, y = 0;
		for (int j = 0; j < 3; ++j)
		{
			x = max(x, v[j]);
			y = max(y, b.v[j]);
		}
		return x < y;
	}
} a[N];
typedef priority_queue<node, vector<node>, greater<node> > PQueue;
PQueue q;
inline void Clear(PQueue &qq)
{
	PQueue qu;
	swap(qq, qu);
}
int n, m, s;
int c[3];
int p[N];
inline int Cost(int i, int k)
{
	int v = -1;
	for (int j = 0; j < 3; ++j)
		if (j != k && a[i].v[j] > v)
			v = a[i].v[j];
	return v - a[i].v[k];
			
}
inline void Solve()
{
	cin >> n;
	m = n / 2;
	s = 0;
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 3; ++j)
			cin >> a[i].v[j];
	fill(c, c + 3, 0);
	fill(p + 1, p + n + 1, -1);
	sort(a + 1, a + n + 1);
	int K = -1;
	for (int i = 1; i <= n; ++i)
	{
		int k = -1, v = -1;
		for (int j = 0; j < 3; ++j)
			if (v < a[i].v[j])
			{
				k = j;
				v = a[i].v[j];
			}
		if (c[k] < m)
		{
			++c[k];
			s += v;
			p[i] = k;
		}
		else
			K = k;
	}
	if (K == -1)
	{
		cout << s << '\n';
		return;
	}
	Clear(q);
	for (int i = 1; i <= n; ++i)
		if (p[i] == K)
			q.push(node(i, Cost(i, K)));
	for (int i = 1; i <= n; ++i)
	{
		if (p[i] != -1)
			continue;
		int y = i; // Loser
		if (Cost(i, K) < q.top().v)
		{
			y = q.top().x;
			s -= a[y].v[K];
			q.pop();
			s += a[i].v[K];
			q.push(node(i, Cost(i, K)));
		}
		s += a[y].v[K] + Cost(y, K);
	}
	cout << s << '\n';
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t-- != 0)
		Solve();
	return 0;
}
