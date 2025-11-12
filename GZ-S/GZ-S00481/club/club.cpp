//GZ-S00481 盘州市第二中学 陈超
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
const int N = 210;
const LL INF = 1e18;

int n;
int cnt[10];
LL f[2*N][N][N];
LL a[100010][5];
bool st[100010];

struct node{
    LL x, id, k;
    bool operator<(const node &w)const{
        return x > w.x;
    }
};
vector<node> sjs;

void solve(){
    cin >> n;
    bool flag = true;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3;j++){
            cin >> a[i][j];
        }
    LL ans = 0;
    if(n > 10000){
        sjs.clear();
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < 3; j++){
                sjs.push_back({a[i][j], i, j});
                cnt[j] = 0;
            }
        memset(st, 0, sizeof st);
        sort(sjs.begin(), sjs.end());
        for(node t : sjs){
            LL x = t.x, id = t.id, k = t.k;
            if(cnt[k] >= n / 2 || st[id]) continue;
            st[id] = true;
            cnt[k]++;
            ans += x;
        }
        cout << ans << endl;
        return;
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n / 2; j++)
            for(int k = 0; k <= n / 2; k++)
                f[i][j][k] = -INF;
    f[0][0][0] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= n / 2; j++)
            for(int k = 0; k <= n / 2; k++){
                int z = i - j - k;
                if(z + 1 <= n / 2) f[i+1][j][k] = max(f[i+1][j][k], f[i][j][k] + a[i+1][2]);
                if(j + 1 <= n / 2) f[i+1][j+1][k] = max(f[i+1][j+1][k], f[i][j][k] + a[i+1][0]);
                if(k + 1 <= n / 2) f[i+1][j][k+1] = max(f[i+1][j][k+1], f[i][j][k] + a[i+1][1]);
            }
    for(int j = 0; j <= n / 2; j++)
        for(int k = 0; k <= n / 2; k++)
            ans = max(ans, f[n][j][k]);
    cout << ans << endl;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
