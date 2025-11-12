#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001], idx=0;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i <= s.length()-1; i++)
	{
		if('0' <= s[i] and s[i] <= '9')
			a[idx++] = (s[i] - '0');
	}
	
	sort(a, a+idx, cmp);
	for(int i = 0; i <= idx-1; i++)
		cout << a[i];
	return 0;
}
