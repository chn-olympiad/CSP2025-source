#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define endl '\n'
const int N = 2e5 + 10;
int n, q;
typedef unsigned long long ull;
ull hs (string s) {
    ull res = 0;
    for (int i = 0; i < s.size(); i ++) res = res * 131 + s[i];
    return res;
}
map<ull, int> rt;
int idx;
int nxt[5000005][30];
int cnt[5000005];
vector<int> hav[5000005];
int pos[N][2];
int in[5000005], out[5000005], tgt;
int ins (int u, string s, int id) {
    for (int i = 0; i < s.size(); i ++) {
        int to = s[i] - 'a';
        if (!nxt[u][to]) nxt[u][to] = ++ idx;
        u = nxt[u][to];
    }
    if (id) hav[u].push_back(id);
    return u;
}
void init (int u) {
    in[u] = ++ tgt;
    for (int i = 0; i < 26; i ++)
        if (nxt[u][i]) init(nxt[u][i]);
    out[u] = tgt;
}
vector<pi> ve;
int ans[N];
vector<pi> qry[5000005];
bool cmp (pi x, pi y) {
    return in[x.first] < in[y.first];
}
void dfs (int u) {
    sort (qry[u].begin(), qry[u].end(), cmp);
    ve.clear();
    for (int x : hav[u]) ve.push_back({in[pos[x][1]], 1}), ve.push_back({out[pos[x][1]] + 1, -1});
    sort (ve.begin(), ve.end());
    int j = 0, len = ve.size(), cnt = 0;
    for (pi e : qry[u]) {
        while (j < len && ve[j].first <= in[e.first]) cnt += ve[j].second, j ++;
        ans[e.second] += cnt;
    }
    for (int i = 0; i < 26; i ++) 
        if (nxt[u][i]) dfs(nxt[u][i]);
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    clock_t __c = clock();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    int sm = 0;
    for (int i = 1; i <= n; i ++) {
        string s, t;
        cin >> s >> t;
        int len = s.size();
        int l = -1, r = -1;
        for (int j = 0; j < len; j ++)
            if (s[j] != t[j]) { l = j; break; }
        for (int j = len - 1; j >= 0; j --)
            if (s[j] != t[j]) { r = j; break; }
        if (l != -1) {
            string tmp = "", tmp2 = "", op;
            for (int j = l; j <= r; j ++) tmp += s[j], tmp2 += t[j];
            op = tmp + '@' + tmp2;
            ull h = hs(op);
            if (!rt[h]) rt[h] = ++ idx;
            tmp = "";
            for (int j = l - 1; j >= 0; j --)
                tmp += s[j];
            pos[i][0] = ins(rt[h], tmp, i);
            tmp = "";
            for (int j = r + 1; j < len; j ++) tmp += s[j];
            pos[i][1] = ins(rt[h], tmp, 0);
            // cout << pos[i][0] << ' ' << pos[i][1] << endl;
        } else {
            // 修改后完全一样->废物，不用管
        }
    }
    for (auto x : rt)
        init (x.second);
    for (int i = 1; i <= q; i ++) {
        string s, t;
        cin >> s >> t;
        int len = s.size();
        if (t.size() != len) ;
        else {  
            int l = -1, r = -1;
            for (int j = 0; j < len; j ++)
                if (s[j] != t[j]) { l = j; break; }
            for (int j = len - 1; j >= 0; j --)
                if (s[j] != t[j]) { r = j; break; }
            string tmp = "", tmp2 = "", op;
            for (int j = l; j <= r; j ++) tmp += s[j], tmp2 += t[j];
            op = tmp + '@' + tmp2;
            ull h = hs(op);
            // 修改部分完全一样
            if (rt.count(h)) {
                int u = rt[h], ___ = 0;
                for (int j = r + 1; j < len; j ++) {
                    if (nxt[u][s[j] - 'a']) u = nxt[u][s[j] - 'a'], ___ = j;
                    else break;
                }
                int rd = u;
                u = rt[h];
                qry[u].push_back({rd, i});
                int __ = 0;
                for (int j = l - 1; j >= 0; j --) {
                    if (nxt[u][s[j] - 'a']) u = nxt[u][s[j] - 'a'], __ = j;
                    else break;
                    qry[u].push_back({rd, i});
                }
            } 
        }
    }
    for (auto x : rt) {
        // cerr << "---" << x.first << ' ' << x.second << endl;
        dfs (x.second);
    }
    for (int i = 1; i <= q; i ++) {
        cout << ans[i] << endl;
    }
    cerr << endl << "RUNTIMES: " << clock() - __c;
    return 0;
}
// 放平心态，没事的