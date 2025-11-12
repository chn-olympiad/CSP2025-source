#include <bits/stdc++.h>
#define MAXN 500001
using namespace std;
int a[MAXN];
struct Node
{
	int l, r, dis;
	bool operator>(const Node &other) const
	{
		return dis > other.dis;
	}
};
priority_queue<Node, vector<Node>, greater<Node>> b;
bitset<MAXN> flag;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = !a[i];
		for (int j = i; j <= n; j++)
		{
			cnt ^= a[j];
			if (cnt == k)
			{
				b.push({i, j, i - j + 1});
			}
		}
	}
	int cnt = 0;
	while (b.size())
	{
		int l = b.top().l, r = b.top().r;
		b.pop();
		bool color = true;
		for (int i = l; i <= r; i++)
		{
			if (flag[i] == true)
			{
				color = false;
				break;
			}
		}
		if (color)
		{
			cnt++;
			for (int i = l; i <= r; i++)
			{
				flag[i] = false;
			}
		}
	}
	cout << cnt;
}
