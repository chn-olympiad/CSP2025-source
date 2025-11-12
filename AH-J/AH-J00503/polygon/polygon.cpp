#include<bits/stdc++.h>
using namespace std;
int a[5010], n, b[5010], k, ans;

bool pd()
{
	//~ printf("k : %d\n", k);
	//~ for (int i = 1; i <= k; i++)
	//~ {
		//~ cout << b[i] << ' ';
	//~ }
	if(k < 3) return false;
	int t = 0;
	//~ cout << endl;
	for (int i = 1; i <= k; i++)
	{
		t += b[i];
	}
	for (int i = 1; i <= k; i++)
		if(b[i] * 2 >= t)
			return false;
	ans++;
	ans %= 998244353;
	//~ printf("ans add to %d\n", ans);
	return true;
}

void solve(int dep)
{
	//~ cout << k << endl;
	for (int i = 1; i <= k; i++)
	{
		//~ cout << b[i] << ' ';
	}
	//~ cout << endl;
	if(dep > n)
	{
		pd();
	}
	else
	{
		k++;
		//~ printf("k add to %d\n", k);
		b[k] = a[dep];
		solve(dep + 1);
		k--;
		solve(dep + 1);
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	solve(1);
	cout << ans;
	return 0;
}
