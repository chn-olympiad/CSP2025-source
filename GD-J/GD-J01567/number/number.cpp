#include<bits/stdc++.h>
using namespace std;
//#define int long long

const int N = 1e6 + 5;

int a[N];

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		int c = s[i];
		if(c >= '0' && c <= '9') a[++cnt] = c - '0';
	}
	sort(a + 1, a + cnt + 1);
	for(int i = cnt; i >= 1; i--)
		cout << a[i];
	
	return 0;
}

