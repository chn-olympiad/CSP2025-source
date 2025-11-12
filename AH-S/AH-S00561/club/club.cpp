#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int       t, n, a[maxn][3], cnt[3], tmp, ans[maxn];
// void f(int x, int i, int dep){
// if (cnt[0] > n/2 && cnt[1] > n/2 && cnt[2] > n/2) return;
// if (cnt[0] > n/2 && cnt[1] > n/2){ans[i] += a[x][2];cnt[2]++;}
// if (cnt[0] > n/2 && cnt[2] > n/2){ans[i] += a[x][1];cnt[1]++;}
// if (cnt[2] > n/2 && cnt[1] > n/2){ans[i] += a[x][0];cnt[0]++;}
// f(x, i, dep+1);
// }
int main(){
    freopen("club.in",  "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        for (int j = 0; j < n; j++){
            cin >> a[j][0] >> a[j][1] >> a[j][2];
            // tmp = 0;
            // for (int k = 0; k < 3; k++){
            //     if (a[j][k] > a[j][tmp]) {
            //         tmp = k;
            //     }
            // }
            // cnt[tmp]++;
            ans[0]+=max(max(a[j][0],a[j][1]), a[j][2]);
        }
        
        // for (int i = 0; i)
        // for (int i = 0; i < 3; i++){
        //     if (cnt[tmp] > n/2){

        //     }
        // }
        cout << ans[0];
    }
    return 0;
}