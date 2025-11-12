#include <bits/stdc++.h>
using namespace std;
#define Mod 998244353
const int N = 505;
int n, m, a[N];
bool flag[N];
string s;

int dfs(int x, int sum, int sum2)
{
	if(x == n + 1)
	{
		if(sum2 >= m) return 1;
		return 0;
	}
	if(sum2 >= m) return 1;
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!flag[i])
		{
			flag[i] = 1;
			res += dfs(x + 1, sum + ((s[i - 1] == '0') || sum >= a[i]), sum2 + ((s[i - 1] == '1') && sum < a[i]));
			flag[i] = 0;
		}
	}
	return res;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	if(n <= 10) cout << dfs(0, 0, 0) - 1;
	return 0;
}