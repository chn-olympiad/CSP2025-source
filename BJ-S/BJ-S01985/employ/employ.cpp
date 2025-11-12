#include <iostream>
#include <cstdio>
using namespace std;

const int N = 510, mod = 998244353;
bool f[N];
int num[N], maxt = -1;

long long jc(int n)
{
	long long ans = 1;
	for (int i = 2; i <= n; i++)
	{
		ans *= n;
		ans %= mod;
	}
	return ans;
}

long long DFS(int n, int m, int now, int nowl)
{
	if (now - nowl >= m)
	{
		return jc(n - now);
	}
	long long ans = 0;
	for (int i = 0; i <= maxt; i++)
	{
		if (num[i] > 0)
		{
			num[i]--;
			ans += DFS(n, m, now + 1, nowl + (!f[now + 1] || nowl >= i)) * (num[i] + 1);
			num[i]++;
		}
		//if (now <= 2) cout << now << " " << ans << endl;
	}
	return ans % mod;
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag1 = true;
	for (int i = 1; i <= n; i++)
	{
		f[i] = (s[i - 1] == '1');
		flag1 = (flag1 && f[i]);
		num[i] = 0;
	}
	int t;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		maxt = max(maxt, t);
		num[t]++;
	}
	if (flag1)
	{
		cout << jc(n) << endl;
		return 0;
	}
	cout << DFS(n, m, 0, 0) << endl;
	return 0;
}