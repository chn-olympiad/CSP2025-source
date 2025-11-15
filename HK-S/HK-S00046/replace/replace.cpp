#include <bits/stdc++.h>
using namespace std;
#define int long long

struct thing {
    string y, x, z;
    int id;
    bool operator < (const thing &b) const {
        return y < b.y;
    }
};

thing conv(string &s, string &t, int id) {
    if (s.size() != t.size() || s == t) return {"_", "", "", id};
    int sz = s.size();
    int l = 0, r = sz-1;
    string y, x, z;
    while (s[l] == t[l]) x += s[l], l++;
    reverse(x.begin(), x.end());
    while (s[r] == t[r]) z += s[r], r--;
    reverse(z.begin(), z.end());
    for (int i=l;i<=r;i++) y += s[i];
    for (int i=l;i<=r;i++) y += t[i];
    return {y, x, z, id};
}

struct event {
    int x, y, t, val;
    bool operator < (const event &b) const {
        if (x != b.x) return x < b.x;
        if (t != b.t) return t < b.t;
        if (y != b.y) return y < b.y;
        return val < b.val;
    }
};

const int maxn = 2e5 + 5, maxL = 6e6 + 5;
int n, q, N, Q;
vector<thing> a, b;
vector<string> ys;
int ysz;
int dc(string y) {return lower_bound(ys.begin(), ys.end(), y) - ys.begin();}
int adj[maxL][26], cnter = 0;
pair<int,int> pos[maxn];

int trans(int u, int i) {
    if (adj[u][i] != -1) return adj[u][i];

    cnter++;
    adj[u][i] = cnter;
    for (int j=0;j<26;j++) adj[cnter][j] = -1;
    return cnter;
}

int euler[maxL], lim[maxL];
void dfs(int u) {
    // if (u < ysz) cout << u << " " << ys[u] << endl;
    cnter++, euler[u] = cnter;
    for (int i=0;i<26;i++) if (adj[u][i] != -1) {
        // cout << u << " " << (char)(i + 'a') << " " << adj[u][i] << endl;
        dfs(adj[u][i]);
    }
    lim[u] = cnter;
}

vector<event> vec;

int fen[maxL];
void update(int id, int val) {
    id++;
    while (id < maxL) {
        fen[id] += val;
        id += (id & -id);
    }
}
int qry(int id) {
    id++;
    int val = 0;
    while (id >= 1) {
        val += fen[id];
        id -= (id & -id);
    }
    return val;
}

int ans[maxn];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i=1;i<=n;i++) {
        string s, t;
        cin >> s >> t;
        a.push_back(conv(s, t, i));
        if (a.back().y == "_") a.pop_back();
    }
    for (int i=1;i<=q;i++) {
        string s, t;
        cin >> s >> t;
        b.push_back(conv(s, t, i));
        // if (i == 101) cout << "test " << b.back().y << " " << b.back().x << " " << b.back().z << endl;
        if (b.back().y == "_") {
            // if (i == 101) cout << "yo\n";
            ans[i] = 0;
            b.pop_back();
        }
    }
    sort(b.begin(), b.end());

    for (thing x:b) ys.push_back(x.y);
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    ysz = ys.size();

    for (int i=0;i<ysz;i++) for (int j=0;j<26;j++) adj[i][j] = -1;
    cnter = ysz-1;
    for (int i=1;i<=q;i++) pos[i] = {-1, -1};
    for (thing x:b) {
        string Y = x.y, X = x.x, Z = x.z;
        int rt = dc(Y);

        int u = trans(rt, 0);
        for (char c:X) u = trans(u, c - 'a');
        pos[x.id].first = u;
        
        u = trans(rt, 1);
        for (char c:Z) u = trans(u, c - 'a');
        pos[x.id].second = u;
        // cout << "test2 " << x.id << " " << pos[x.id].first << " " << pos[x.id].second << endl;
    }

    // cout << cnter << endl;
    cnter = -1;
    for (int i=0;i<ysz;i++) dfs(i);
    // cout << cnter << endl;

    // cout << pos[101].first << " " << pos[101].second << endl;
    // cout << euler[pos[101].first] << " " << euler[pos[101].second] << endl;

    for (int i=1;i<=q;i++) if (pos[i].first != -1) {
        vec.push_back({euler[pos[i].first], euler[pos[i].second], 1, i});
    }

    // for (int i=0;i<9;i++) cout << euler[i] << " "; cout << endl;

    for (thing x:a) {
        string Y = x.y, X = x.x, Z = x.z;
        int rt = dc(Y);
        if (rt >= ysz || ys[rt] != Y) continue;

        int u = adj[rt][0];
        if (u == -1) continue;
        for (char c:X) {
            u = adj[u][c - 'a'];
            if (u == -1) break;
        }
    
        int v = adj[rt][1];
        if (v == -1) continue;
        for (char c:Z) {
            v = adj[v][c - 'a'];
            if (v == -1) break;
        }
        // cout << "A " << x.id << " " << u << " " << v << endl;
        if (u == -1 || v == -1) continue;
        vec.push_back({euler[u], euler[v], 0, 1});
        vec.push_back({lim[u] + 1, euler[v], 0, -1});
        vec.push_back({euler[u], lim[v] + 1, 0, -1});
        vec.push_back({lim[u] + 1, lim[v] + 1, 0, 1});
    }

    sort(vec.begin(), vec.end());

    for (event E:vec) {
        int y = E.y, val = E.val;
        if (E.t == 0) update(y, val);
        else ans[val] = qry(y);
    }

    for (int i=1;i<=q;i++) cout << ans[i] << "\n";
    


}