#include <bits/stdc++.h>
using namespace std;
string s;
long long ans2,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] <= '9' && s[i] >='0')
		{
			ans2++;
			if(s[i] == '0')
			{
				a[ans2] = 0;
			}
			if(s[i] == '1')
			{
				a[ans2] = 1;
			}
			if(s[i] == '2')
			{
				a[ans2] = 2;
			}
			if(s[i] == '3')
			{
				a[ans2] = 3;
			}
			if(s[i] == '4')
			{
				a[ans2] = 4;
			}
			if(s[i] == '5')
			{
				a[ans2] = 5;
			}
			if(s[i] == '6')
			{
				a[ans2] = 6;
			}
			if(s[i] == '7')
			{
				a[ans2] = 7;
			}
			if(s[i] == '8')
			{
				a[ans2] = 8;
			}
			if(s[i] == '9')
			{
				a[ans2] = 9;
			}
		}
	}
	for(int i = 1;i <= ans2;i++)
	{
		for(int j = 1;j < ans2;j++)
		{
			if(a[j] < a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(int i = 1;i <= ans2;i++)
	{
		cout << a[i];
	}
	return 0;
}
