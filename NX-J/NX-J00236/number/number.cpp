#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int f = 0, l = s.size();
	for(int i = 0; i < l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			f++;
			a[f] = s[i] - '0';
		}
	}
	sort(a + 1, a + f + 1);
	for(int i = f; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
