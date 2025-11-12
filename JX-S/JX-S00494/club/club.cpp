#include <bits/stdc++.h>
using namespace std;
#define int long long
void read(int &x) {
    x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch <= '9' && ch >= '0'){
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
}
const int maxn = 1e5 + 5;
int n;
int ans, a[maxn][5];
struct node{
    int id, val;
    node(int a = 0, int b = 0): id(a), val(b){}
    friend bool operator < (node e1, node e2){
        return e1.val > e2.val;
    }
} tmp[maxn];
void dfs(int id, int cnt1, int cnt2, int cnt3, int sum1, int sum2, int sum3){
    if(id == n + 1){
        ans = max(ans, sum1 + sum2 + sum3);
        return;
    }
    if(cnt1 < n / 2) dfs(id + 1, cnt1 + 1, cnt2, cnt3, sum1 + a[id][1], sum2, sum3);
    if(cnt2 < n / 2) dfs(id + 1, cnt1, cnt2 + 1, cnt3, sum1, sum2 + a[id][2], sum3);
    if(cnt3 < n / 2) dfs(id + 1, cnt1, cnt2, cnt3 + 1, sum1, sum2, sum3 + a[id][3]);
}
void solve1(){
    //for(int i = 1; i <= n; i ++) for(int j = 1; j <= 3; j ++) read(a[i][j]);
    dfs(1, 0, 0, 0, 0, 0, 0);
    printf("%lld\n", ans);
}
int b[maxn];
void solve2(){
    for(int i = 1; i <= n; i ++) b[i] = a[i][1];
    sort(b + 1, b + n + 1);
    reverse(b + 1, b + n + 1);
    for(int i = 1; i <= n / 2; i ++) ans += b[i];
    printf("%lld\n", ans);
}
void solve3(){
    for(int i = 1; i <= n; i ++) tmp[i] = node(i, abs(a[i][1] - a[i][2]));
    sort(tmp + 1, tmp + n + 1);
    int cnt[3] = {0, 0, 0}, sum[3] = {0, 0, 0};
    for(int i = 1; i <= n; i ++){
        int idd = tmp[i].id;
        int maxx = max(a[idd][1], a[idd][2]);
        int id = (a[idd][1] == maxx ? 1 : 2);
        if(cnt[id] < n / 2) {
            sum[id] += maxx;
            cnt[id] ++;
        }
        else {
            sum[id % 2 + 1] += min(a[idd][1], a[idd][2]);
            cnt[id % 2 + 1] ++;
        }
    }
    printf("%lld\n", sum[1] + sum[2]);
}
struct poi{
    int id, a, b, ida, idb;
    poi(int _id = 0, int _a = 0, int _b = 0, int _ida = 0, int _idb = 0): id(_id), a(_a), b(_b), ida(_ida), idb(_idb){}
} p[maxn];
void solve(){
    ans = 0;
    read(n);
    bool flag1 = true, flag2 = true;
    for(int i = 1; i <= n; i ++) {
        read(a[i][1]), read(a[i][2]), read(a[i][3]);
        if(a[i][2] ^ 0 || a[i][3] ^ 0) flag1 = false;
        if(a[i][3] ^ 0) flag2 = false;
    }
    /*
    if(n <= 30){
        solve1();
        return;
    }
    if(flag1){
        solve2();
        //return;
    }
    if(flag2){
        solve3();
        return;
    }
    */
    for(int i = 1; i <= n; i ++){
        if(a[i][1] >= a[i][2]){
            if(a[i][2] >= a[i][3]) p[i] = poi(i, a[i][1], a[i][2], 1, 2);
            else if(a[i][3] >= a[i][1]) p[i] = poi(i, a[i][3], a[i][1], 3, 1);
            else p[i] = poi(i, a[i][1], a[i][3], 1, 3);
        }
        else {
            if(a[i][1] >= a[i][3]) p[i] = poi(i, a[i][2], a[i][1], 2, 1);
            else if(a[i][3] >= a[i][2]) p[i] = poi(i, a[i][3], a[i][2], 3, 2);
            else p[i] = poi(i, a[i][2], a[i][3], 2, 3);
        }
    }
    for(int i = 1; i <= n; i ++) tmp[i] = node(i, p[i].a - p[i].b);
    sort(tmp + 1, tmp + n + 1);
    int cnt[4] = {0, 0, 0, 0}, sum[4] = {0, 0, 0, 0};
    for(int i = 1; i <= n; i ++){
        int id = tmp[i].id;
        int a = p[id].a, b = p[id].b, ida = p[id].ida, idb = p[id].idb;
        if(cnt[ida] < n / 2) {
            cnt[ida] ++;
            sum[ida] += a;
        }
        else {
            cnt[idb] ++;
            sum[idb] += b;
        }
    }
    printf("%lld\n", sum[1] + sum[2] + sum[3]);
}
 main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    read(T);
    while(T --) solve();
    return 0;
}
/*
4
1 0 0
2 0 0
3 0 0
4 0 0

*/
