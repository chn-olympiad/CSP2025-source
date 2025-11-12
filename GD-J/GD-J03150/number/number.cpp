#include <bits/stdc++.h>

using namespace std;

string s;

int cnt[1000];

int t;

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	
	int n = s.length();
	
	for (int i=0; i<n; i++)
	{
		t = s[i];
			
		++cnt[t];
	}
	
	for (int i='9'; i>='0'; i--)
	{
		while (cnt[i] > 0)
		{
			cout << i-'0';
			
			--cnt[i];
		}
	}
	
	return 0;
}
