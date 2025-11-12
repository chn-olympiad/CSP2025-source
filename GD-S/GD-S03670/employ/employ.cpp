#include<bits/stdc++.h>
using namespace std;
int n, m, c[505], tot = 0, cnt = 0;
char s[505];
const long long mod = 998244353;
long long sum = 0;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if(s[i] == '1')
			tot++;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		if(c[i] == 0)
			cnt++;
	}
	if(tot < m || (n - cnt) < m)
	{
		cout << 0 << endl;
		return 0;
	}
	if((tot == n && (n - cnt) >= m) || m == 1)
	{
		sum = 1;
		for(int i = n; i >= 1; i--)
		{
			sum = 1ll * sum * i;
			sum %= mod;
		}
		cout << sum << endl;
		return 0;
	}
	sum = (n*n*m % mod)*(n*(m-tot)*(tot + cnt) % mod) % mod;
	cout << sum << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
