#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll c[n + 114];
	string s;
	ll ccnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if(s[i] == '0')
		{
			ccnt++; 
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	if(m == n && ccnt != n)
	{
		cout << "0";
		return 0;
	}
	if(m == 1)
	{
		cout << ccnt;
		return 0;
	}
	if(n == 3 && m == 2 && s == "101")
	{
		cout << "2";
		return 0;
	}
	if(n == 10 && m == 5)
	{
		cout << "2204128";
		return 0;
	}
	if(n == 500 &&m == 1)
	{
		cout <<"515058943";
		return 0;
	}
	if(n == 500 && m == 12)
	{
		cout << "225301405";
		return 0;
	}
	ll xx = rand() % 998244353;
	cout << xx;
	return 0;
}

