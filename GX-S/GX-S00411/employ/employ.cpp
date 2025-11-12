#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
struct node{
    int x, y, z, c;
}a[N];
bool cmp(node A, node B){
   return A.c < B.c;
}
void solve(){
    long long ans = 0;
    memset(a, 0, sizeof(a));
    cin >> n;
    for(int i = 1; i <= n; i++) a[i].c = 10000000;
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].z;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; i++){
        int mx = max({a[i].x, a[i].y, a[i].z});
        if(a[i].x == mx) cnt1++, ans += a[i].x;
        else if(a[i].y == mx) cnt2++, ans += a[i].y;
        else cnt3++, ans += a[i].z;
    }
    if(cnt1 * 2 > n){
        for(int i = 1;  i <= n; i++)
            if(a[i].x >= max(a[i].z, a[i].y)) a[i].c = (a[i].x - max(a[i].z, a[i].y));
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= cnt1 - (n / 2); i++) ans -= a[i].c;
    }else if(cnt2 * 2 > n){
        for(int i = 1;  i <= n; i++)
            if(a[i].y >= max(a[i].z, a[i].x)) a[i].c = (a[i].y - max(a[i].z, a[i].x));
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= cnt2 - (n / 2); i++) ans -= a[i].c;
    }else if(cnt3 * 2 > n){
        for(int i = 1;  i <= n; i++)
            if(a[i].z >= max(a[i].x, a[i].y)) a[i].c = (a[i].z - max(a[i].x, a[i].y));
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= cnt3 - (n / 2); i++) ans -= a[i].c;
    }
     cout << ans << "\n";
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
