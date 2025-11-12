#include <bits/stdc++.h>
using namespace std;

int a[1000005] = {};

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k = 1;
	cin >> s;
	int n = s.length();
	s = " " + s;
	for(int i = 1;i <= n;i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[k] = s[i] - '0';
			k++;
		}
	}
	sort(a + 1,a + k,cmp);
	for(int i = 1;i <= k - 1;i++)
	{
		cout << a[i];
	}
	return 0;
} 
