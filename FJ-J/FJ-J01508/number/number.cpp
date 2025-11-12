#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int a[N];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	s = "!" + s;
	int n = s.size() - 1;
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			a[j] = (s[i] - '0');
			j++;
		}
	}
	j--;
	sort(a + 1, a + j + 1);
	if(a[j] == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for(int i = j; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
