#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int _ = 1e5 + 10;
struct intention
{
	int a, i;e
}w1[_], w2[_], w3[_];
int vis[_];
void init()
{
	memset(w1, 0, sizeof(w1));
	memset(w2, 0, sizeof(w2));
	memset(w3, 0, sizeof(w3));
	memset(vis, 0, sizeof(vis));
}
void solve();
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
void solve()
{
	init();
	int n, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	ll ans = 0;
	cin >> n;
	priority_queue<pair<int, int>> pq1, pq2, pq3;
	while (!pq1.empty())
		pq1.pop();
	while (!pq2.empty())
		pq2.pop();
	while (!pq3.empty())
		pq3.pop();
	for (int i = 1; i <= n; i++)
	{
		cin >> w1[i].a >> w2[i].a >> w3[i].a;
		w1[i].i = i, w2[i].i = i, w3[i].i = i;
		int temp = 0, temp2 = 0;
		temp2 = max(w1[i].a, w2[i].a);
		temp = max(temp2, w3[i].a);
		if (temp == w1[i].a)
		{
			vis[i] = 1, cnt1++;
			pq1.push({-(temp - max(w2[i].a, w3[i].a)), i});
		}
		else if (temp == w2[i].a)
		{
			vis[i] = 2, cnt2++;
			pq2.push({-(temp - max(w1[i].a, w3[i].a)), i});
		}
		else if (temp == w3[i].a)
		{
			vis[i] = 3, cnt3++;
			pq3.push({-(temp - max(w1[i].a, w2[i].a)), i});
		}
		ans += temp;
	}
	while (cnt1 > n / 2)
	{
		int k = pq1.top().second;
		ans += pq1.top().first;
		pq1.pop();
		cnt1--;
	}
	while (cnt2 > n / 2)
	{
		int k = pq2.top().second;
		ans += pq2.top().first;
		pq2.pop();
		cnt2--;
	}
	while (cnt3 > n / 2)
	{
		
		int k = pq3.top().second;
		ans += pq3.top().first;
		pq3.pop();
		cnt3--;
	}
	cout << ans << '\n';
}

