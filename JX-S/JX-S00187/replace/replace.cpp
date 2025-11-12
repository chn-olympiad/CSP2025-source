#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
string s[N][3], t[3];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> s[i][1] >> s[i][2];
    while(q--)
    {
        cin >> t[1] >> t[2];
        if(t[1].size() != t[2].size())
        {
            cout << "0\n";
            continue;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
			auto x = t[1].find(s[i][1]);
			if(x != 2ull * LLONG_MAX + 1)
			{
				string st = t[1].substr(0, x) + s[i][2] +
				                                t[1].substr(x + s[i][2].size());
				if(st == t[2]) ans++;
			}
        }
        cout << ans << '\n';
    }
    return 0;
}
