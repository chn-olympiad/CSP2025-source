#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
struct Node
{
	int ind, a[4];
};
int n, maxans = 0;
int cnt[4];
Node a[N];
bool cmp()
{
	for (int i = 1; i <= 3; i++)
	{
		if (cnt[i] > n / 2)
			return 1;
	}
	return 0;
}
void dfs(int step, int sum)
{
	if (cmp())
		return;
	if (step > n)
	{
		maxans = max(maxans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		a[step].ind = i;
		cnt[i]++;
		dfs(step + 1, sum + a[step].a[i]);
		a[step].ind = 0;
		cnt[i]--;
	}
	return;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
		dfs(1, 0);
		cout << maxans << endl;
		maxans = 0;
	}
	return 0;
}
