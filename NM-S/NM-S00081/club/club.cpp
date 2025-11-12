#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][5];
int tmp[N];
int n;
int ans = 0;
inline bool cmp(int x, int y){
    return x > y;
}
inline void dfs(int id, int club, int tot, int a1, int a2, int a3){
    if(id == n){
        ans = max(ans, tot);
    }
    if(a1 + 1 <= n / 2){
        dfs(id + 1, 0, tot + a[id + 1][0], a1 + 1, a2, a3);
    }
    if(a2 + 1 <= n / 2){
        dfs(id + 1, 1, tot + a[id + 1][1], a1, a2 + 1, a3);
    }
    if(a3 + 1 <= n / 2){
        dfs(id + 1, 2, tot + a[id + 1][2], a1, a2, a3 + 1);
    }
}
inline void solve1(){
    memset(tmp, 0, sizeof tmp);
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        tmp[++cnt] = a[i][0];
    }
    sort(tmp + 1, tmp + cnt + 1, cmp);
    for(int i = 1;i <= n / 2;i++){
        ans += tmp[i];
    }
    cout << ans << '\n';
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int a10 = 0, a20 = 0;
        for(int i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if(a[i][1] == 0){
                a10++;
            }
            if(a[i][2] == 0){
                a20++;
            }
        }
        if(a10 == n && a20 == n){
            solve1();
        }else{
            ans = 0;
            dfs(0, 0, 0, 0, 0, 0);
            cout << ans << '\n';
        }
    }
    return 0;
}
