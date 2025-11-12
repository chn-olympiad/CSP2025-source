#include <bits/stdc++.h>
#define ll long long
#define fi  first
#define se second
using namespace std;
const int N = 2e5 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9')
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
int n, q;
string s[N][2];
map<string, map<string, int> > mp; 
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), q = read();
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1], mp[s[i][0]][s[i][1]]++;
	while(q--)
	{
		string t[2];
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size())
		{
			puts("0");
			continue;
		}
		printf("%d\n", mp[t[0]][t[1]]);
	}
	return 0;
}

