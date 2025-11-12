#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second

const int N = 2.5e6 + 5;
const int B = 131;

int n, m;

bool AAA;

struct ac {
    int tot, tr[N][26], fail[N], ed[N], pre[N];
    vector<int> v[N];
    void insert(string s, int id) {
        int x = 0;
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i] - 'a';
            if (!tr[x][ch]) tr[x][ch] = ++tot;
            x = tr[x][ch];
        }
        ed[x] = id;
    }
    void dfs(int x, int fa) {
        if (!x) pre[x] = -1;
        pre[x] = pre[fa];
        if (ed[x]) pre[x] = x;
        for (int y : v[x])
            dfs(y, x);
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (tr[0][i]) q.push(tr[0][i]);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (tr[x][i]) {
                    fail[tr[x][i]] = tr[fail[x]][i];
                    q.push(tr[x][i]);
                }
                else tr[x][i] = tr[fail[x]][i];
            }
        }
        for (int i = 1; i <= tot; i++)
            v[fail[i]].push_back(i);
        dfs(0, 0);
    }
} tr1, tr2;

map<pii, int> mp;

ull H1[N], H2[N], pw[N];

ull get1(int l, int r) {
    if (l > r) return 0;
    return H1[r] - (l ? H1[l - 1] * pw[r - l + 1] : 0);
}

ull get2(int l, int r) {
    if (l > r) return 0;
    return H2[r] - (l ? H2[l - 1] * pw[r - l + 1] : 0);
}

ull calc1(int l1, int r1, int l2, int r2) {
    return get1(l1, r1) * pw[r2 - l2 + 1] + get1(l2, r2);
}

ull calc2(int l1, int r1, int l2, int r2) {
    return get2(l1, r1) * pw[r2 - l2 + 1] + get2(l2, r2);
}

int len[N];
bool BBB;

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    pw[0] = 1;
    for (int i = 1; i < N; i++)
        pw[i] = pw[i - 1] * B;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        len[i] = s1.length();
        tr1.insert(s1, i), tr2.insert(s2, i);
    }
    tr1.build(), tr2.build();
    while (m--) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < t1.length(); i++) {
            H1[i] = (i ? H1[i - 1] * B : 0) + t1[i] - 'a';
            H2[i] = (i ? H2[i - 1] * B : 0) + t2[i] - 'a';
        }
        int x = 0;
        mp.clear();
        for (int i = 0; i < t1.length(); i++) {
            int ch = t1[i] - 'a';
            x = tr1.tr[x][ch];
            int t = tr1.pre[x];
            while (t != -1) {
                mp[{tr1.ed[t], i}] = 1;
                t = tr1.pre[tr1.fail[t]];
            }
        }
        int ans = 0;
        x = 0;
        for (int i = 0; i < t2.length(); i++) {
            int ch = t2[i] - 'a';
            x = tr2.tr[x][ch];
            int t = tr2.pre[x];
           // cout << i << ' ' << t << endl;
            while (t != -1) {
                if (mp[{tr2.ed[t], i}]) {
                    ull h1 = calc1(0, i - len[tr2.ed[t]], i + 1, t2.length() - 1);
                    ull h2 = calc2(0, i - len[tr2.ed[t]], i + 1, t2.length() - 1);
                    if (h1 == h2) ans++;
                }
                t = tr2.pre[tr2.fail[t]];
            }
        }
        cout << ans << '\n';
    }
   // cerr<<((&AAA)-(&BBB))/1024.0/1024<<"MB\n";
    return 0;
}