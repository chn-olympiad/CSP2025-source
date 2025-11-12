#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], c[N];
int cha[N];

struct Node
{
	int val, id;
};

void solve()
{
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int ans = 0;
	queue <pii> q1, q2, q3;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		ans += max({a[i], b[i], c[i]});
		if (a[i] > b[i] && a[i] > c[i])
		{
			q1.push({a[i], i});
			cnt1++;
		}
		else if (b[i] > a[i] && b[i] > c[i])
		{
			q2.push({b[i], i});
			cnt2++;
		}
		else if (c[i] > a[i] && c[i] > b[i])
		{
			q3.push({c[i], i});
			cnt3++;
		}
	}
	if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2)
	{
		cout << ans << endl;
		return ;
	}
//	cout << 91 << endl;
	int top = 0;
	if (cnt1 > n / 2)
	{
		while (!q1.empty())
		{
			pii tp = q1.front();
			q1.pop();
			int val = tp.fi, id = tp.se;
			cha[++top] = val - max(b[id], c[id]);
		}
		sort(cha + 1, cha + top + 1);
		int i = 1;
		while (cnt1 > n / 2)
		{
			ans -= cha[i];
			i++;
			cnt1--;
		}
	}
	else if (cnt2 > n / 2)
	{
		while (!q2.empty())
		{
			pii tp = q2.front();
			q2.pop();
			int val = tp.fi, id = tp.se;
			cha[++top] = val - max(a[id], c[id]);
		}
		sort(cha + 1, cha + top + 1);
		int i = 1;
		while (cnt2 > n / 2)
		{
			ans -= cha[i];
			i++;
			cnt2--;
		}
	}
	else if (cnt3 > n / 2)
	{
		while (!q3.empty())
		{
			pii tp = q3.front();
			q3.pop();
			int val = tp.fi, id = tp.se;
			cha[++top] = val - max(a[id], b[id]);
		}
		sort(cha + 1, cha + top + 1);
		int i = 1;
		while (cnt3 > n / 2)
		{
			ans -= cha[i];
			i++;
			cnt3--;
		}
	}
	cout << ans << endl;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("1.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}
