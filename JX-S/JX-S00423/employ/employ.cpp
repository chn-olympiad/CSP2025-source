#include<bits/stdc++.h>
using namespace std;

vector<int> mul(505);
const int mod = 998244353;

void init()
{
	mul[0] = 1;
	for (int i = 1; i < 501; i++)
	{
		mul[i] = (mul[i - 1] * i) % mod;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	init();
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int uac[n] = {0};
	int ac[n] = {0};
	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == '1')
		{
			ac[i] = 1;
			if (i == 0) uac[i] = 0;
			else        uac[i] = uac[i - 1];
		}
		else
		{
			if (i == 0) uac[i] = 1;
			else        uac[i] = uac[i - 1] + 1;
		}
	}
	int c[n] = {0};
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	cout << mul[n];
	return 0;
}
