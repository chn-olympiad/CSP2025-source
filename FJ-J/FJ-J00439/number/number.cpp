#include <bits/stdc++.h>

using namespace std;

const int N = 15;

string s;
int t[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	cin >> s;
	for (int i = 0; i < s.length(); i ++ )
	{
		if (s[i] >= '0' && s[i] <= '9') t[s[i] - '0'] ++ ;
	}
	for (int i = 9; i >= 0; i -- )
	{
		for (int j = 1; j <= t[i]; j ++ ) putchar(i + '0'); 
	}
	return 0;
}
 
