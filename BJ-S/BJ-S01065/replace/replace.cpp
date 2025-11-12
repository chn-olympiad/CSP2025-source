#include <bits/stdc++.h>
using i128 = __int128;
using ll = long long;
using namespace std;
const int MAXN = 2e5 + 5, MAXM = 5e6 + 5;
i128 MOD = 17636684157303059, base, base2;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
class Graph{
private:
    const static int MAXNODE = MAXM, MAXEDGE = MAXM;
    struct Edge{
        int v, next;
    };
    int tot;
public:
    int h[MAXNODE];
    Edge t[MAXEDGE];
    void addEdge(int u, int v){
        ++tot;
        t[tot].v = v;
        t[tot].next = h[u];
        h[u] = tot;
    }
}G;
class SegmentTree{
private:
    const static int MAXNODE = 8 * MAXN;
    #define ls (id << 1)
    #define rs (id << 1 | 1)
    struct Node{
        int l, r;
        int add;
    }t[MAXNODE];
    void buildTree(int id, int l, int r){
        t[id].l = l, t[id].r = r, t[id].add = 0;
        if (l == r){
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(ls, l, mid);
        buildTree(rs, mid + 1, r);
    }
    void change(int id, int l, int r, int val){
        if (t[id].l == l && t[id].r == r){
            t[id].add += val;
            return;
        }
        if (r <= t[ls].r){
            change(ls, l, r, val);
        }else if (l >= t[rs].l){
            change(rs, l, r, val);
        }else{
            change(ls, l, t[ls].r, val);
            change(rs, t[rs].l, r, val);
        }
    }
    int query(int id, int pos){
        if (t[id].l == t[id].r){
            return t[id].add;
        }
        if (pos <= t[ls].r){
            return t[id].add + query(ls, pos);
        }else{
            return t[id].add + query(rs, pos);
        }
    }
public:
    void init(int n){
        buildTree(1, 1, n);
    }
    void change(int l, int r, int val){
        change(1, l, r, val);
    }
    int query(int pos){
        return query(1, pos);
    }
}seg;
int ch[MAXM][26], tot, tot2;
bool flag[MAXM], flag2[MAXM];
int siz[MAXM];
int id[MAXM];
vector<pair<int, int>> vec[MAXM][2];
int insert(string s, int rt){
    int p = rt, len = s.length();
    for (int i = 0; i < len; i++){
        if (!ch[p][s[i] - 'a']){
            ch[p][s[i] - 'a'] = ++tot;
            G.addEdge(p, tot);
        }
        p = ch[p][s[i] - 'a'];
    }
    return p;
}
int query(string s, int rt){
    int p = rt, len = s.length();
    for (int i = 0; i < len; i++){
        if (!ch[p][s[i] - 'a']){
            break;
        }
        p = ch[p][s[i] - 'a'];
    }
    return p;
}
void dfs(int u, int pre, int fa){
    if (flag[u] || fa == 0){
        ++tot2;
        siz[u] = 1;
        pre = tot2;
    }
    id[u] = pre;
    for (int i = G.h[u]; i; i = G.t[i].next){
        int v = G.t[i].v;
        if (v == fa){
            continue;
        }
        dfs(v, pre, u);
        siz[u] += siz[v];
    }
}
int ans[MAXN];
void dfs2(int u, int fa){
    for (auto v: vec[u][0]){
        // cout << id[v.first] << ' ' << id[v.first] + siz[v.first] - 1 << endl;
        seg.change(id[v.first], id[v.first] + siz[v.first] - 1, 1);
    }
    for (auto v: vec[u][1]){
        ans[v.second] = seg.query(id[v.first]);
    }
    for (int i = G.h[u]; i; i = G.t[i].next){
        int v = G.t[i].v;
        if (v == fa){
            continue;
        }
        dfs2(v, u);
    }
    for (auto v: vec[u][0]){
        seg.change(id[v.first], id[v.first] + siz[v.first] - 1, -1);
    }
}
ll getHash(string s, string t){
    int len = s.length();
    i128 res = 0;
    for (int i = 0; i < len; i++){
        res = (res * base + (s[i] - 'a' + 1)) % MOD;
    }
    i128 res2 = 0;
    for (int i = 0; i < len; i++){
        res2 = (res2 * base + (t[i] - 'a' + 1)) % MOD;
    }
    return (res * base2 + res2) % MOD;
}
unordered_map<ll, vector<tuple<string, string, int>>> mp[2];
string s1, s2;
void insert(int type, int id){
    int len = s1.length();
    int p1, p2;
    for (int i = 0; i < len; i++){
        if (s1[i] != s2[i]){
            p1 = i - 1;
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--){
        if (s1[i] != s2[i]){
            p2 = i + 1;
            break;
        }
    }
    string t1 = "", t2 = "";
    for (int i = p1 + 1; i <= p2 - 1; i++){
        t1 += s1[i];
        t2 += s2[i];
    }
    string pre = "", suf = "";
    for (int i = p1; i >= 0; i--){
        pre += s1[i];
    }
    for (int i = p2; i < len; i++){
        suf += s1[i];
    }
    mp[type][getHash(t1, t2)].push_back({pre, suf, id});
}
vector<tuple<string, string, int>> ve1, ve2;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    base = rng() % (MOD - 100) + 100;
    base2 = rng() % (MOD - 100) + 100;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> s1 >> s2;
        if (s1 == s2){
            continue;
        }
        insert(0, 0);
    }
    for (int i = 1; i <= q; i++){
        cin >> s1 >> s2;
        if (s1.length() != s2.length()){
            continue;
        }
        insert(1, i);
    }
    seg.init(2 * n);
    for (auto y: mp[0]){
        ve1 = y.second;
        int rt1 = ++tot;
        int rt2 = ++tot;
        ve2 = mp[1][y.first];
        if (ve1.empty() || ve2.empty()){
            continue;
        }
        for (auto x: ve1){
            int id1 = insert(get<0>(x), rt1);
            int id2 = insert(get<1>(x), rt2);
            flag[id2] = true;
            vec[id1][0].push_back({id2, 0});
        }
        for (auto x: ve2){
            int id1 = query(get<0>(x), rt1);
            int id2 = query(get<1>(x), rt2);
            flag2[id2] = true;
            vec[id1][1].push_back({id2, get<2>(x)});
        }
        dfs(rt2, 0, 0);
        dfs2(rt1, 0);
    }
    for (int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}