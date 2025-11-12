#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int N = 5e3 + 5;
const int M = 998244353;
int n, ans, a[N];
bool check(vector<int>& v)
{
	if(v.size() < 3) return false;
	int sum = 0, mx = 0;
	for(int x : v)
	{
		sum += x;
		mx = max(mx, x);
	}
	return sum > mx * 2;
}
void dfs(int x, vector<int>& v)
{
	if(x == n + 1)
	{
		if(check(v))
		{
			ans++;
			ans %= M;
		}
		return;
	}
	v.push_back(a[x]);
	dfs(x + 1, v);
	v.pop_back();
	dfs(x + 1, v);
	return;
}
int f(int x, int y)
{
	int t1 = 1, t2 = 1;
	for(int i = 2; i <= x; i++)
		t1 *= i;
	for(int i = 2; i <= y; i++)
		t2 *= i;
	for(int i = 2; i <= x - y; i++)
		t2 *= i;
	return t1 / t2;
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool flag = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] != 1) flag = false;
	}
	if(flag)
	{
		for(int i = 3; i <= n; i++)
		{
			ans += f(n, i);
			ans %= M;
		}
		cout << ans << endl;
		return 0;
	}
	if(n < 3)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<int> v;
	dfs(1, v);
	cout << ans << endl;
	return 0;
}
