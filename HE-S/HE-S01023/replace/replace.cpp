#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 10, M = 4e6 + 10, inf = 1e6 + 10;
int n, q, len, u, v, f[M], w[N];
string s1, s2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int j = 1; j <= n; j++)
	{
		cin >> s1 >> s2;
		s1 = " " + s1, s2 = " " + s2;
		len = s1.length();
		for (int i = 1; i <= len; i++)
			if (s1[i] == 'b')
			{
				u = i;
				break;
			}
		for (int i = 1; i <= len; i++)
			if (s2[i] == 'b')
			{
				v = i;
				break;
			}
		w[j] = v - u;
	}
	while (q--)
	{
		cin >> s1 >> s2;
		s1 = " " + s1, s2 = " " + s2;
		len = s1.length();
		for (int i = 1; i <= len; i++)
			if (s1[i] == 'b')
			{
				u = i;
				break;
			}
		for (int i = 1; i <= len; i++)
			if (s2[i] == 'b')
			{
				v = i;
				break;
			}
		for (int i = 1; i <= n; i++)
			for (int j = v - u; j >= 1 - u; j--)
			{
				f[j + inf] = max(f[j + inf], 1);
				if (j >= w[i])
					f[j + inf] += f[j + inf - w[i]];
			}	
		cout << f[v - u + inf] << '\n';
	}
}
/*
3 1
aab aba
aaaaaaabaa aaaaaaabaa
abaa aaab
aaaaabaaaa aaaaaaabaa
*/
