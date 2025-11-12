#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e5 + 10;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while('0' > ch || ch > '9'){ if(ch == '-'){ w = -1;} ch = getchar();}
	while('0' <= ch && ch <= '9') s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
	return s * w;
}
string s;
int num[N];
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	s = "!" + s;
	for(int i = 1; i <= n; i++) if('0' <= s[i] && s[i] <= '9') num[s[i] - '0']++;
	for(int i = 9; ~i; i--)
	{
		while(num[i]) printf("%d", i), num[i]--;
	}
	return 0;
}
