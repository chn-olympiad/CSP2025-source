#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
struct node{
    int x;
    int rs;
    int y;
    int z;
} sum[5], a[100005];
int n;
int t;
int ans;
bool cmp(node x,node y){
    return x.x > y.x;
}
/**bool cmp2(node x,node y){
    return x.b > y.b;
}
bool cmp3(node x,node y){
    return x.c > y.c;
}*/
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t --){
        ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i ++){
            cin >> a[i].x >> a[i].y >> a[i].z;
            a[i].rs = i;
        }
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1;i <= n / 2;i ++){
            sum[1].rs += a[i].x;
        }
        cout << sum[1].rs << "\n";
    }
    return 0;
}
