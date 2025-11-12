#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long cnt = 0;
long long num = 1;
long long num2 = 1;
long long js = 0;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w",stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if(x == 0)
		{
			js++;
		}
	}
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '1') cnt++;
	}
	if(cnt != num && m == n)
	{
		cout << 0;
		return 0;
	}
	if(cnt == s.size())
	{
		for(int i = 1; i <= js; i++)
		{
			num = ((num % mod) * (i % mod)) % mod;
		}
		for(int i = 1; i <= n - js; i++)
		{
			num2 = ((num2 % mod) * (i % mod)) % mod;
		}
		cout << (num * num2) % mod;
		return 0;
	}
	if(cnt <= 18)
	{
		if(cnt < m) 
		{
			cout << 0;
			return 0;
		}
	}
	return 0;
}
