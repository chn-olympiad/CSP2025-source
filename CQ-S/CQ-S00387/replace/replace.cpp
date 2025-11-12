#include <bits/stdc++.h>
using namespace std;

const int B = 13331;
int n, m;
unsigned long long h[200001][2], h2[5000001][2], b[5000001];
string s[200001][2], t[2000001][2];
map <pair <unsigned long long, unsigned long long>, int> mp;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i][0] >> s[i][1];
        for (auto j : s[i][0])
            h[i][0] = h[i][0] * B + j;
        for (auto j : s[i][1])
            h[i][1] = h[i][1] * B + j;
        mp[{h[i][0], h[i][1]}]++;
    }
    b[0] = 1;
    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] * B;
    for (int i = 1; i <= m; i++) {
        cin >> t[i][0] >> t[i][1];
        int len = t[i][0].size();
        t[i][0] = " " + t[i][0] + " ";
        t[i][1] = " " + t[i][1] + " ";
        for (int j = 1; j <= len; j++)
            h2[j][0] = h2[j - 1][0] * B + t[i][0][j];
        for (int j = 1; j <= len; j++)
            h2[j][1] = h2[j - 1][1] * B + t[i][1][j];
        long long ans = 0;
        for (int j = 0; j <= len; j++) {
            if (t[i][0][j] != t[i][1][j])
                break;
            for (int k = len + 1; k > j + 1; k--) {
                if (t[i][0][k] != t[i][1][k])
                    break;
                ans += mp[{h2[k - 1][0] - h2[j][0] * b[k - j - 1], h2[k - 1][1] - h2[j][1] * b[k - j - 1]}];
            }
        }
        printf("%lld\n", ans);
    }
}