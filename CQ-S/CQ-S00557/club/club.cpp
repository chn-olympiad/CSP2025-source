/* expect : 100 pts */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
using namespace std;

const int N = 100010, INF = 1e9;
int T, n, a[N][3], c[N];

inline void sol()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j <= 2; ++j)
			cin >> a[i][j];
	int cnt[3] = {0, 0, 0}, base = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= 2; ++j)
		{
			if(a[i][j] == max({a[i][0], a[i][1], a[i][2]}))
			{
				base += a[i][j];
				++cnt[j]; c[i] = j;
				break;
			}
		}
	}
	int id = 0;
	for(int i = 0; i <= 2; ++i) if(cnt[i] > n / 2) id = i;
	vector < int > tmp;
	for(int i = 1; i <= n; ++i)
	{
		if(c[i] == id)
		{
			int mx = -INF;
			for(int j = 0; j <= 2; ++j)
				if(j != id)
					mx = max(mx, a[i][j]);
			tmp.push_back(a[i][id] - mx);
		}
	}
	sort(tmp.begin(), tmp.end());
	for(int x : tmp) if(cnt[id] > n / 2) --cnt[id], base -= x;
	cout << base << '\n';
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) sol();
	return 0;
}
/*
g++ club.cpp -o club -O2 -std=c++14 -static -Wall -DLOCAL -Wno-unused-result
./club
*/
