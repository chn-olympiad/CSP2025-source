#include<bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int maxn = 2e5 + 5;///
int n, q;
string s[maxn][2], t[maxn][2];

namespace solve1{
    bool check(){
        return n <= 1e3 && q <= 1e3;
    }
    const int mod = 1e9 + 9;
    const int mod1 = 998244353;
    struct Hash{
        int a[2];
        Hash(int x = 0, int y = 0){
            a[0] = x;
            a[1] = y;
        }
    }base(13131, 23333), pw[maxn];
    bool operator == (Hash x, Hash y){
        return x.a[0] == y.a[0] && x.a[1] == y.a[1];
    }
    int ad(int x, int y, int mod){
        return x + y >= mod ? x + y - mod : x + y;
    }
    Hash operator + (Hash x, Hash y){
        return Hash(ad(x.a[0], y.a[0], mod), ad(x.a[1], y.a[1], mod1));
    }
    Hash operator + (Hash x, int y){
        return Hash(ad(x.a[0], y, mod), ad(x.a[1], y, mod1));
    }
    Hash operator * (Hash x, Hash y){
        return Hash(1ll * x.a[0] * y.a[0] % mod, 1ll * x.a[1] * y.a[1] % mod1);
    }
    Hash operator - (Hash x, Hash y){
        return Hash(ad(x.a[0], mod - y.a[0], mod), ad(x.a[1], mod1 - y.a[1], mod1));
    }
    Hash sum1[maxn][2];
    Hash sum[maxn][2];
    void init(){
        int N = 2000;
        pw[0] = Hash(1, 1);
        for(int i = 1; i <= N; i++) pw[i] = pw[i - 1] * base;
    }
    Hash query(int l, int r, int op){
        return sum[r][op] - sum[l - 1][op] * pw[r - l + 1];
    }
    void solve(){
        init();
        for(int i = 1; i <= n; i++){
            for(char c : s[i][0]){
                sum1[i][0] = sum1[i][0] * base + c;
            }
            for(char c : s[i][1]){
                sum1[i][1] = sum1[i][1] * base + c;
            }
        }
        for(int i = 1; i <= q; i++){
            int m = t[i][0].size();
            t[i][0] = " " + t[i][0];
            t[i][1] = " " + t[i][1];
            for(int j = 1; j <= m; j++){
                sum[j][0] = sum[j - 1][0] * base + t[i][0][j];
                sum[j][1] = sum[j - 1][1] * base + t[i][1][j];
            }
            int ans = 0;
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= n; k++){
                    if(j + s[k][0].size() - 1 <= m && sum1[k][0] == query(j, j + s[k][0].size() - 1, 0)){
                        Hash x = sum[m][0];
                        x = x - query(j, j + s[k][0].size() - 1, 0) * pw[m - (j + s[k][0].size() - 1)];
                        x = x + sum1[k][1] * pw[m - (j + s[k][0].size() - 1)];
                        if(x == sum[m][1]){
                            ans++;
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}

namespace solve2{
    const int maxm = 5e6 + 5;
    int tmp[maxn << 1], m;
    struct node{
        int l, r, i;
    };
    vector<node> a[maxn << 1];
    int b[maxn][2], c[maxn][2];
    int find(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b'){
                return i;
            }
        }
        return -1;
    }
    namespace BIT{
    #define lowbit(x) (x & (-x))
        int tree[maxm];
        void add(int x, int y){
            x++;
            for(; x < maxm; x += lowbit(x)) tree[x] += y;
        }
        int query(int x){
            int sum = 0;
            x++;
            for(; x; x -= lowbit(x)) sum += tree[x];
            return sum;
        }
        int query(int l, int r){
            return query(r) - query(l - 1);
        }
    }
    int ans[maxn];
    void solve(){
        for(int i = 1; i <= n; i++){
            int pos1 = find(s[i][0]), pos2 = find(s[i][1]);
            b[i][0] = pos1;
            b[i][1] = pos2;
            tmp[++m] = pos1 - pos2;
        }
        for(int i = 1; i <= q; i++){
            int pos1 = find(t[i][0]), pos2 = find(t[i][1]);
            c[i][0] = pos1;
            c[i][1] = pos2;
            tmp[++m] = pos1 - pos2;
        }
        sort(tmp + 1, tmp + m + 1);
        m = unique(tmp + 1, tmp + m + 1) - tmp - 1;
        for(int i = 1; i <= n; i++){
            int x = b[i][0] - b[i][1];
            x = lower_bound(tmp + 1, tmp + m + 1, x) - tmp;
            a[x].pb(node{b[i][0], (int)s[i][0].size() - b[i][0], 0});
        }
        for(int i = 1; i <= q; i++){
            int x = c[i][0] - c[i][1];
            x = lower_bound(tmp + 1, tmp + m + 1, x) - tmp;
            a[x].pb({c[i][0], (int)t[i][0].size() - c[i][0], i});
        }
        for(int i = 1; i <= m; i++){
            if(!a[i].size()){
                continue;
            }
            sort(a[i].begin(), a[i].end(), [](node x, node y){
                return x.l < y.l;
            });
            for(int j = 0; j < (int)a[i].size(); j++){
                int k = j;
                while(k + 1 < (int)a[i].size() && a[i][k + 1].l == a[i][j].l){
                    k++;
                }
                for(int x = j; x <= k; x++){
                    if(a[i][x].i == 0){
                        BIT::add(a[i][x].r, 1);
                    }
                }
                for(int x = j; x <= k; x++){
                    if(a[i][x].i != 0){
                        ans[a[i][x].i] = BIT::query(a[i][x].r);
                    }
                }
                j = k;
            }
            for(int j = 0; j < (int)a[i].size(); j++){
                if(!a[i][j].i){
                    BIT::add(a[i][j].r, -1);
                }
            }
        }
        for(int i = 1; i <= q; i++){
            cout << ans[i] << '\n';
        }
    }
}

signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s[i][0] >> s[i][1];
    }
    for(int i = 1; i <= q; i++){
        cin >> t[i][0] >> t[i][1];
    }
    if(solve1::check()){
        solve1::solve();
        return 0;
    }
    solve2::solve();

    return 0;
}