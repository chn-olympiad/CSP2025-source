# include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10, MAXM = 7e5 + 10;
int n, q;
string a, b;
vector <int> t[MAXN];
int ch[MAXM][680], ed[MAXM], tot;
int fail[MAXM], dep[MAXM];
int f[MAXM][25];
long long g[MAXM][25];
void insert(int id) {
    int nod = 0;
    for (int i = 0; i < t[id].size(); i++) {
        // cout << id << " " << x << endl ;
        int x = t[id][i];
        if (!ch[nod][x]) ch[nod][x] = ++tot, dep[tot] = dep[nod] + 1;
        nod = ch[nod][x];
    }
    ed[nod]++;
    // cout << id << " " << nod << endl ;
}
void bfs() {
queue <int> q;
    for (int i = 0; i < 676; i++) {
        if (ch[0][i]) {
            q.push(ch[0][i]);
            // fail[ch[0][i]] = 0;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 676; i++) {
            if (!ch[u][i]) {
                ch[u][i] = ch[fail[u]][i];
                continue;
            }
            fail[ch[u][i]] = ch[fail[u]][i];
            q.push(ch[u][i]);
        }
    }
    for (int i = 0; i <= tot; i++) f[i][0] = fail[i], g[i][0] = ed[i];
    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i <= tot; i++) f[i][j] = f[f[i][j - 1]][j - 1], g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];

    }
    // cout << f[4][0] << endl ;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        int len = a.size();
        for (int j = 0; j < len; j++) {
            // cout << j << endl ;
            t[i].push_back((a[j] - 'a') * 26 + b[j] - 'a');
        }
        insert(i);
    }
    // return 0;
    bfs();
    // cerr << tot << endl ;
    // cerr << f[18][1] << endl ;
    // cout << fail[4] << " " << f[4][0] << endl ;
    for (int i = 1; i<= q; i++) {
        cin >> a >> b;
        int len = a.size();
        if (len != b.size()) {
            cout << 0 << endl ;
            continue;
        }
        long long ans = 0;
        int nod = 0, l = 0, r = 0;
        for (int j = 0; j < len; j++) if (a[j] != b[j]) {
            l = j;
            break;
        }
        for (int j = len - 1; j >= 0; j--) {
            if (a[j] != b[j]) {
                r = j;
                break;
            }
        }
        for (int j = 0; j < len; j++) {
            int c = (a[j] - 'a') * 26 + b[j] - 'a';
            nod = ch[nod][c];
            if (j >= r) {
                int tmp = nod;
                // while (tmp && dep[tmp] >= j - l + 1) {
                //     cout << tmp << " " ;
                //     ans += ed[tmp];
                //     tmp = fail[tmp];
                // }
                // cout << f[tmp][0] << " " << dep[f[tmp][0]] << endl ;
                // if (i == 2715) cout << dep[tmp] << " " << dep[fail[tmp]] << " " << dep[f[tmp][1]] << endl ;
                for (int k = 20; k >= 0; k--) {
                    if (dep[f[tmp][k]] >= j - l + 1) {
                        // if (i == 2715) cout << tmp << " " << k << " " << f[tmp][k] << " " << g[tmp][k] << endl ;
                        ans += g[tmp][k];
                        tmp = f[tmp][k];
                    }
                }
                if (dep[tmp] >= j - l + 1) {
                    ans += ed[tmp];
                    // cout << tmp << endl ;
                }
                // if (i == 2715) cout << j << " " << ans << endl ;
            }
        }
        cout << ans << endl ;

    }
    return 0;
}