#include <bits/stdc++.h>
using namespace std;
string s;
int n,x;
int a[1000009]; 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	x = s.size();
	for (int i = 1;i <= x ;i++)
	{
		cin >> s[i];
		if ((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5' )||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9'))
		{
			n++;
			a[n]=s[i];
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i+1;j <= n;j++)
		{
			if (a[j] > a[i])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cout << a[i];
	}
	return 0;
}
