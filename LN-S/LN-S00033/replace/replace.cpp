#include<bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 2e5 + 10;
string s[maxn][3];
int b[maxn];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> s[i][1] >> s[i][2];
    if(q == 1) {
        string sa, sb;
        cin >> sa >> sb;
        if(sa.find(s[1][1]) == std::string::npos) {
            cout << 0;
            return 0;
        }
        int fa = sa.find(s[1][1]);
        int cnt = 0;
        for(int i = fa; i <= fa + s[1][2].size() - 1; i++) {
            sa[i] = s[1][2][cnt];
            cnt++;
        }
        cout << (sa == sb);
        return 0;
    }
    while(q--) {
        string sa, sb;
        cin >> sa >> sb;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int f1 = s[i][1].find('b');
            int f2 = s[i][2].find('b');
            int fa = sa.find('b');
            int fb = sb.find('b');
            if(s[i][1].size() - 1 - f1 > sa.size() - 1 - fa)
                continue;
            if(f1 > fa)
                continue;
            if(f2 - f1 == fb - fa)
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}
