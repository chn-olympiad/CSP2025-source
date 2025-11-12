#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
const ll inf = 1e18;
ll n, tot, ans, a[N][5], tp[N];
bool vis[5];
vector<int> v[5];
struct node{
    ll val, id, to;
}b[N];
inline bool judge(){
    if(max(v[1].size(), max(v[2].size(),v[3].size()))<=n/2) return 1;
    return 0;
}
inline void solve(int now){
    for(int i:v[now]){
        ll pre = a[i][tp[i]], res = -inf, pos = 0;
        for(int j=1; j<=3; ++j){
            if(vis[j]) continue;
            if(a[i][j]-pre>res){
                res = a[i][j] - pre;
                pos = j;
            }
        }b[++tot] = {res, i, pos};
    }
    sort(b+1, b+tot+1, [](auto x, auto y){return x.val>y.val;});
    int m = v[now].size() - n/2;
    for(int i=1; i<=m; ++i){
        ans += b[i].val;
        // cout << "+= "<<b[i].val<<endl;
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> n; ans = tot = 0;
        memset(vis, 0, sizeof(vis));
        v[1].clear(), v[2].clear(), v[3].clear();
        for(int i=1; i<=n; ++i){
            cin >> a[i][1] >> a[i][2] >> a[i][3];

            ll x = a[i][1], y = a[i][2], z = a[i][3];
            if(x>=max(y,z)){
                v[1].push_back(i);
                ans += x; tp[i] = 1;
            }else if(y>=max(x,z)){
                v[2].push_back(i);
                ans += y; tp[i] = 2;
            }else{
                v[3].push_back(i);
                ans += z; tp[i] = 3;
            }
        }
        if(judge()){
            cout << ans << endl;
            // cout << "cut\n";
            continue;
        }
        int x = v[1].size(), y = v[2].size(), z = v[3].size();
        if(x>=max(y,z)){
            vis[1] = 1;
            solve(1);
        }else if(y>=max(x,z)){
            vis[2] = 1;
            solve(2);
        }else{
            vis[3] = 1;
            solve(3);
        }cout << ans << endl;
    }
return 0;}