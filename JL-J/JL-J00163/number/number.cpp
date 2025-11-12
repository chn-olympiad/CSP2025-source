#include <bits/stdc++.h>
using namespace std;
string s;
int l, n;
int a[1000005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for(int i=0;i<l;i++)
	{
		if((s[i]-'0') >= 0&&(s[i]-'0') <= 9)
		{
			a[i] = s[i] - '0';
			n++;
		}
	}
	sort(a, a+l, cmp);
	for(int i=0;i<n;i++)
	{
		cout << a[i];
	}
	return 0;
}
