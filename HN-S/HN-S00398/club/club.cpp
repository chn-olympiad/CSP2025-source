#include <bits/stdc++.h>
#define rep(i,x,y) for(int i = x; i <= y;i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define int long long
using namespace std;

const int MAXN = 1e5 + 5;

int T, n, a[MAXN][3];

int cnt[3];

int ans;
int choose[MAXN];
int t[MAXN], tot;
void solve(){
    cin >> n;
    cnt[0] = cnt[1] = cnt[2] = 0;
    ans = 0;
    rep(i, 1, n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    rep(i, 1, n){
        int mx = max({a[i][0], a[i][1], a[i][2]});
        if(a[i][0] == mx) {
            cnt[0]++, ans += a[i][0];
            choose[i] = 0;
        }else if(a[i][1] == mx){
            cnt[1]++, ans += a[i][1];
            choose[i] = 1;
        }else{
            cnt[2]++, ans += a[i][2];
            choose[i] = 2;
        }

    }
    tot = 0;
    if(cnt[0] > n / 2){

        rep(i, 1, n) {
            if(choose[i] == 0){
                t[++tot] = max(a[i][1] - a[i][0], a[i][2] - a[i][0]);
            }
        }
        sort(t + 1, t + 1 + tot, greater<int>());
        rep(i, 1, cnt[0] - n / 2){
            ans += t[i];
        }
    }else if(cnt[1] > n / 2){

        rep(i, 1, n) {
            if(choose[i] == 1){
                t[++tot] = max(a[i][0] - a[i][1], a[i][2] - a[i][1]);
            }
        }
        sort(t + 1, t + 1 + tot, greater<int>());
        rep(i, 1, cnt[1] - n / 2){
            ans += t[i];
        }
    }else{

        rep(i, 1, n) {
            if(choose[i] == 2){
                t[++tot] = max(a[i][1] - a[i][2], a[i][0] - a[i][2]);
            }
        }
        sort(t + 1, t + 1 + tot, greater<int>());
        rep(i, 1, cnt[2] - n / 2){
            ans += t[i];
        }
    }
    cout << ans << '\n';

}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    for(cin >>T;T--;solve());
    return 0;
}
