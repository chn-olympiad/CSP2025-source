#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("number.in","r" ,stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	int i;
	int flag = 0;
	int p[100000+10];
	for (i = 0;i < a.length();i++)
	{
		if ('0' <= a[i] && a[i] <= '9') p[flag++] = a[i] - '0';
	}
	sort(p,p+flag);
	for (int i = flag-1;i >= 0;i--)
	{
		cout << p[i];
	}
	return 0;
	
 } 
