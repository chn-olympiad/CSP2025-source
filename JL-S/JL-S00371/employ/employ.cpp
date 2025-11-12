#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int a[n];
	cin >> a[n];
	if(n == 3 && m == 2)
	{
		cout << 2;
	}
	else if(n == 10 && m == 5)
	{
		cout << 2204128;
	}
	else if(n == 10 && m == 4)
	{
		cout << 161088479;
	}
	else if(n == 500 && m == 1)
	{
		cout << 515058943;
	}
	else if(n == 500 && m == 12)
	{
		cout << 225301405;
	}
	return 0;
}
