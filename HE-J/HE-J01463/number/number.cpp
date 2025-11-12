#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
string s;
char c[N];
int k;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			k++;
			c[k] = s[i];
		}
	}
	sort(c + 1, c + k + 1);
	for (int i = k; i >= 1; i--)
	{
		cout << c[i];
	}
	return 0;
}
