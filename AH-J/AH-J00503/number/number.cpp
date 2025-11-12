#include<bits/stdc++.h>
using namespace std;
int a[11];
int if_num(char x)
{
	if(x >= '0' && x <= '9')
		return int(x - '0');
	return -1;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		int k = if_num(s[i]);
		if(k != -1)
			a[k]++;
	}
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; j++)
			cout << i;
	return 0;
}
