#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int n = s.length();
	int num = 1;
	for (int i = 0 ; i < n ; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[num] = s[i] - '0';
			num++;
		}
	}
	sort(a + 1,a + num + 1,cmp);
	for (int i = 1 ; i <= num - 1 ; i++)
	{
		cout << a[i];
	}
	return 0;
}
