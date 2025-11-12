#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 10;
string s;
int a[N], k;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			a[++k] = int(s[i] - '0');
		}
	}
	sort(a + 1, a + k + 1);
	reverse(a + 1, a + k + 1);
	if (a[1] == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			cout << a[i];
		}
	}
	return 0;
}
