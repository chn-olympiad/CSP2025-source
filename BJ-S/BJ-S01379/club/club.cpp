#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int MAXN = 1e5 + 11;
struct node{
    i64 id, val;
}a[MAXN][3 + 11];
struct node2{
    i64 val;
    i64 x, y, z;
}b[3 * MAXN];
bool cmp2(node2 n1, node2 n2){
    if(n1.val > n2.val){
        return true;
    }
    if(n1.val == n2.val){
        return a[n1.x][3].val > a[n2.x][3].val;
    }
    return false;
}
bool vis[MAXN];
void s(i64 u){
    if(a[u][3].val < a[u][2].val){
        swap(a[u][3], a[u][2]);
    }
    if(a[u][2].val < a[u][1].val){
        swap(a[u][2], a[u][1]);
    }
    if(a[u][3].val < a[u][2].val){
        swap(a[u][3], a[u][2]);
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    i64 T;
    cin >> T;
    while(T--){
        memset(vis, 0, sizeof(vis));
        i64 n;
        cin >> n;
        i64 ans = 0;
        for(i64 i = 1; i <= n; ++i){
            cin >> a[i][1].val >> a[i][2].val >> a[i][3].val;
            a[i][1].id = 1, a[i][2].id = 2, a[i][3].id = 3;
            s(i);
            b[i].y = a[i][3].id;
            b[i].z = a[i][2].id;
            b[i].val = a[i][3].val - a[i][2].val;
            b[i].x = i;
        }
        sort(b + 1, b + n + 1, cmp2);
        i64 cnt[4] = {0, 0, 0, 0};
        for(i64 i = 1; i <= n; ++i){
            i64 x = b[i].x, y = b[i].y, z = b[i].z;
            if(cnt[y] < n / 2){
                ans += a[x][3].val;
                cnt[y]++;
            }else{
                ans += a[x][2].val;
                cnt[z]++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
