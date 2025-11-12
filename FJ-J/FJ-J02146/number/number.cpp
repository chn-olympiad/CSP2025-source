#include <bits/stdc++.h>
using namespace std;
int n[1000005], num;
string s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.length();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			n[num++] = s[i]-'0';
		}
	}
	sort(n, n+num, cmp);
	for (int i = 0; i < num; i++)
	{
		cout << n[i];
	}
	
	return 0;
}
