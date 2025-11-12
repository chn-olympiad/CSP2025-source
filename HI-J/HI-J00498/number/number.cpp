#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long a[100005],num = 0;
	for (int i = 1;i <= s.size();i++)
	{
		if (s[i] >= '1' && s[i] <= 9)
		{
			s[i] -= '0';
			a[i] == s[i];
			num++;
		}
	}
	sort(a + 1,a + s.size() + 1);
	for (int i = num;i >= 1;i--)
	{
		cout << a[i];
	}
} 
