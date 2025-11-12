#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, l, r) for(int i = (r); i >= (l); i--)
#define FRE(NAME) freopen(NAME".in", "r", stdin), freopen(NAME".out", "w", stdout);
#define int long long
#define endl '\n'
#define pb push_back
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
const int MAXN = 10010, MAXM = 1000010;

struct edge{
    int l, r;
    int val;
};

int getfa(int u, vector<int> &fa){
    if(fa[u] == u) return u;
    return fa[u] = getfa(fa[u], fa);
}

void merge(int i, int j, vector<int> &fa){
    i = getfa(i, fa), j = getfa(j, fa);
    fa[i] = j;
}

int getans(int n, vector<edge> e){
    vector<int> fa(n + 10);
    rep(i, 1, n + 9) fa[i] = i;
    int ans = 0, cnt = 0;
    for(auto u : e){
        if(cnt == n - 1) break;
        if(getfa(u.l, fa) != getfa(u.r, fa)){
            merge(u.l, u.r, fa);
            ans += u.val;
            cnt++;
        }
    }
    return ans;
}

vector<edge> vmerge(vector<edge> m1, vector<edge> m2){
    int i = 0, j = 0;
    vector<edge> res;
    while(i < m1.size() && j < m2.size()){
        if(m1[i].val <= m2[j].val){
            res.push_back(m1[i]);
            i++;
        }else{
            res.push_back(m2[j]);
            j++;
        }
    }
    while(i < m1.size()) res.push_back(m1[i]), i++;
    while(j < m2.size()) res.push_back(m2[j]), j++;
    return res;
}

bool cmp(edge a, edge b){
    return a.val < b.val;
}

int aans = 0x3f3f3f3f3f3f3f3f;

void dfs(vector<vector<edge>> &a, vector<int> &c, int &k, 
         int res, vector<edge> now, 
         int cnt, int cntk){
    if(cnt == k + 1){
        // cout << cntk << " " << res + getans(cntk, now) << endl;
        // for(auto u : now){
        //     cout << u.l << ' ' << u.r << ' ' << u.val << endl;
        // }
        // cout << endl << endl << endl;
        aans = min(aans, res + getans(cntk, now));
        return;
    }
    dfs(a, c, k, res, now, cnt + 1, cntk);
    now = vmerge(now, a[cnt]);
    res += c[cnt];
    cntk++;
    dfs(a, c, k, res, now, cnt + 1, cntk);
}

i32 main(){
    FRE("road");
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> e(m), new_e;
    for(auto &u : e) cin >> u.l >> u.r >> u.val;
    sort(e.begin(), e.end(), cmp);

    // cout << "---1---" << endl;

    vector<int> fa(n + 1);
    rep(i, 1, n) fa[i] = i;
    int ans = 0, cnt = 0;
    for(auto u : e){
        if(cnt == n - 1) break;
        if(getfa(u.l, fa) != getfa(u.r, fa)){
            new_e.pb(u);
            merge(u.l, u.r, fa);
            ans += u.val;
            cnt++;
        }
    }
    aans = ans;

    // cout << "---2---" << endl;
    // cout << ans << endl;
    vector<int> c(k + 1);
    vector<vector<edge>> a(k + 1);
    rep(i, 1, k){
        // cout << i << endl;
        cin >> c[i];
        rep(j, 1, n){
            int w;
            cin >> w;
            // cout << n + i << " " << j << " " << w << endl;
            a[i].push_back({n + i, j, w});
            // cout << w << " ";
        }
        sort(a[i].begin(), a[i].end(), cmp);
        // cout << endl << a[i].size() << endl;
    }

    // cout << "---3---" << endl;

    dfs(a, c, k, 0, new_e, 1, n);

    cout << aans << endl;
    return 0;
}

/*
g++ k.cpp -o k -Wall -Wextra -O2 -g3 -DQwQ
./k
*/