//orz Divinsword_Liao
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int T, n, a[100010][10], cnt[10];
long long ans;

constexpr inline int mmin(const int a, const int b)
{
	return (a < b ? a : b);
}

constexpr inline int mmax(const int a, const int b)
{
	return (a < b ? b : a);
}

struct node
{
	int x, y, z;
	node(int a, int b, int c) : x(a), y(b), z(c) {}
	node() = default;
	inline bool operator<(const node _) const
	{
		return x - mmax(y, z) > _.x - mmax(_.y, _.z);
	}
};

priority_queue<node> pq[4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		pq[1] = priority_queue<node>();
		pq[2] = priority_queue<node>();
		pq[3] = priority_queue<node>();
//		while (!pq[1].empty())
//			pq[1].pop();
//		while (!pq[2].empty())
//			pq[2].pop();
//		while (!pq[3].empty())
//			pq[3].pop();
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++)
		{
			int mxn = a[i][1], num = 1;
			if (a[i][2] > mxn)
			{
				mxn = a[i][2];
				num = 2;
			}
			if (a[i][3] > mxn)
			{
				mxn = a[i][3];
				num = 3;
			}
			cnt[num] ++;
			if (num == 1)
				pq[num].emplace(a[i][1], a[i][2], a[i][3]);
			if (num == 2)
				pq[num].emplace(a[i][2], a[i][1], a[i][3]);
			if (num == 3)
				pq[num].emplace(a[i][3], a[i][1], a[i][2]);
			ans += a[i][num];
		}
//		cerr << "DBG" << ans << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << '\n';
		if (cnt[1] > (n / 2))
		{
			while (cnt[1] > (n / 2))
			{
				node i = pq[1].top();
				pq[1].pop();
				ans -= i.x;
				ans += mmax(i.y, i.z);
				cnt[1]--;
				if (cnt[1] <= (n / 2))
					break;
			}
		}
		if (cnt[2] > (n / 2))
		{
			while (cnt[2] > (n / 2))
			{
				node i = pq[2].top();
				pq[2].pop();
				ans -= i.x;
				ans += mmax(i.y, i.z);
				cnt[2]--;
				if (cnt[2] <= (n / 2))
					break;
			}
		}
		if (cnt[3] > (n / 2))
		{
			while (cnt[3] > (n / 2))
			{
				node i = pq[3].top();
//				cerr << "DBG" << i.x << ' ' << i.y << ' ' << i.z << '\n'; 
				pq[3].pop();
				ans -= i.x;
				ans += mmax(i.y, i.z);
				cnt[3]--;
				if (cnt[3] <= (n / 2))
					break;
			}
		}
		cout << ans << '\n';
	}
}
/*
1
30
6090 4971 4101
14495 19657 10011
6294 14948 17496
3266 18897 6963
3129 14412 12639
5331 7102 7590
12533 15635 16270
2339 16892 11211
6980 3113 19980
16859 13322 9404
16742 1573 8946
1285 5253 2697
18072 16412 5595
15870 17311 7711
19194 4644 11192
1306 6558 10317
11128 16814 5947
1603 6202 15251
4014 5797 2498
1557 4235 12431
1561 16149 16433
9399 1760 809
13383 18379 10169
7679 4131 17310
2900 8148 13627
14783 19510 17642
19717 4666 6335
9868 5451 19561
11196 1774 11436
10753 10148 6994
*/
