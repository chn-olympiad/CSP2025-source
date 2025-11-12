#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int c = 1, s = 0;
	char ch = getchar();
	for (;!isdigit(ch);ch = getchar()) if (ch == '-') c = -1;
	for (;isdigit(ch);ch = getchar()) s = (s << 1) + (s << 3) + (ch ^ '0');
	return c * s;
}

const int N = 200010;

int n, q;
string s1[N], s2[N], t1[N], t2[N], qz[N][5 * 1000010], qz1[N];

int main()
{
//	freopen("replace.in", "r", stdin);
//	freopen("replace.out", "w", stdout);
	cin.tie(0);
	n = read();q = read();
	for (int i = 1;i <= n;i++)
	{
		cin >> s1[i] >> s2[i];
		int len = s1[i].length();
		qz1[0] = s1[0];
		for (int j = 1;j < len;j++) qz1[j] = qz1[j - 1] + s1[i][j];
		for (int j = 1;j < len;j++)
		{
			for (int lens = j - 1;lens > 0;lens--)
			{
				string s, ss;
				for (int x = 0;x < j - lens;x++)
				{
					s += s1[i][x];
				}
				for (int x = lens;x < j;x++)
				{
					ss += s1[i][x];
				}
				if (s == ss)
				{
					qz[i][j] = lens;
				}
			}
		}
	}
	for (int i = 1;i <= n;i++) cout << s1[i] << endl;
	return 0;
}

