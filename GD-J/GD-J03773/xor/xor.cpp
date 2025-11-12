#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
#define x first
#define y second

const int N = 5e5 + 10;

int n, k, a[N];
vector<pii> seg;

inline int cmp(pii u, pii v)
{
	return (u.y != v.y ? u.y < v.y : u.x > v.x);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 1; i <= n; ++i)
	{
		int sum = 0;
		for (int j = i; j >= 1; --j)
		{
			sum ^= a[j];
			if (sum == k) 
				seg.push_back({j, i});
		}
	}
	
	sort(seg.begin(), seg.end(), cmp);
	
	int r = seg[0].y, ans = 1;
	for (int i = 1; i < (int)seg.size(); ++i)
		if (seg[i].x > r)
		{
			r = seg[i].y;
			ans++;
		}
	cout << ans << endl;
	
	return 0;
}
