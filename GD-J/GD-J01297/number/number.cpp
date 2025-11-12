#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define LLL __int128
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

namespace gdb7
{
	signed main(void) {
		freopen("number.in", "r", stdin);
		freopen("number.out", "w", stdout);
		string s, ans;
		cin >> s;
		for (auto i: s) {
			if (isdigit(i)) {
				ans += i;
			}
		}
		sort(ans.begin(), ans.end(), greater<char>());
		cout << ans << endl;
		return 0;
	}
}

signed main(void)
{
	return gdb7::main();
}

