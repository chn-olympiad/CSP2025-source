#include <bits/stdc++.h>
using namespace std;

int a[1000005]; 

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int cur = 0;
	for (int i=0;i<s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[++cur] = int(s[i]) - 48;
		}
	}
	sort(a+1,a+cur+1);
	for (int i=cur;i>=1;i--)
	{
		cout << a[i];
	}
	return 0;
} 