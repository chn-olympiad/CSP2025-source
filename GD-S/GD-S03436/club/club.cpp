#include <bits/stdc++.h>

using namespace std;

int arr[100010][3];
int n;
int s[3];

int dfs(int sum, int num)
{
	if (num == n)
	{
		return sum;
	}
	int maxn = 0;
	for (int i = 0; i < 3; i++)
	{
		s[i]++;
		if (s[i] > n / 2)
		{
			s[i]--;
			continue;
		}
		maxn = max(maxn, dfs(sum + arr[num][i], num + 1));
		s[i]--;
	}
	return maxn;
}

int main(void)
{
	freopen("club.in", "w", stdin);
	freopen("club.out", "r", stdout);
	int t = 0;
	cin >> t;
	for (; t > 0; t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		}
		cout << dfs(0, 0) << endl;
	}
	return 0;
}
