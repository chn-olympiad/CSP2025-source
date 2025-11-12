#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int N = 2e5 + 10, L = 5e6 + 10;
int n, q, tl[L][26], tr[L][26], idx, cnt[L];
vector<int> vec[L];
map<string, int> mp;
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    IOS;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s, t, x = "";
        cin >> s >> t;
        int len = s.size(), l = 0, r = len - 1;
        for (;l < len and s[l] == t[l]; l++);
        if (l >= len)
            continue;
        for (;r >= 0 and s[r] == t[r]; r--);
        for (int i = l; i <= r; i++)
            x = x + s[i];
        x = x + " ";
        for (int i = l; i <= r; i++)
            x = x + t[i];
        int root;
        if (!mp.count(x))
            root = mp[x] = ++idx;
        else
            root = mp[x];
        int u = root;
        for (int i = l - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (!tl[u][c])
                tl[u][c] = ++idx;
            u = tl[u][c];
        }
        vec[u].push_back(i);
        u = root;
        for (int i = r + 1; i < len; i++) {
            int c = s[i] - 'a';
            if (!tr[u][c])
                tr[u][c] = ++idx;
            u = tr[u][c];
        }
        vec[u].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        string s, t, x = "";
        cin >> s >> t;
        int len = s.size(), l = 0, r = len - 1, cl = 0, cr = 0;
        for (;l < len and s[l] == t[l]; l++);
        for (;r >= 0 and s[r] == t[r]; r--);
        for (int i = l; i <= r; i++)
            x = x + s[i];
        x = x + " ";
        for (int i = l; i <= r; i++)
            x = x + t[i];
        if (!mp.count(x)) {
            cout << "0\n";
            continue;
        }
        int root = mp[x], u = root, ans = 0;
        for (int j : vec[root]) {
            cnt[j]++;
            if (cnt[j] == 2)
                ans++;
        }
        for (int i = l - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (!tl[u][c])
                break;
            u = tl[u][c];
            for (int j : vec[u]) {
                cnt[j]++;
                if (cnt[j] == 2)
                    ans++;
            }
        }
        u = root;
        for (int i = r + 1; i < len; i++) {
            int c = s[i] - 'a';
            if (!tr[u][c])
                break;
            u = tr[u][c];
            for (int j : vec[u]) {
                cnt[j]++;
                if (cnt[j] == 2)
                    ans++;
            }
        }
        cout << ans << "\n";
        for (int j : vec[root])
            cnt[j]--;
        u = root;
        for (int i = l - 1; i >= 0; i--) {
            int c = s[i] - 'a';
            if (!tl[u][c])
                break;
            u = tl[u][c];
            for (int j : vec[u])
                cnt[j]--;
        }
        u = root;
        for (int i = r + 1; i < len; i++) {
            int c = s[i] - 'a';
            if (!tr[u][c])
                break;
            u = tr[u][c];
            for (int j : vec[u])
                cnt[j]--;
        }
    }
    return 0;
}
/*
5 1
b c
aab aac
aaab aaac
aaaab aaaac
aaaaab aaaaac
aaab aaac
*/
