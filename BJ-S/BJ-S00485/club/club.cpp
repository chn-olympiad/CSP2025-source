#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn][10], vis[5], bes[maxn];
struct node{
    int x, y, z;
}res[maxn];

bool cmp(node a, node b){
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y > b.y;
    return a.z > b.z;
}

void solve(int n){
    if (n == 2){
        int ans = 0;
        for (int i = 1; i <= 3; i ++){
            for (int j = 1; j <= 3; j ++){
                    if (i == j) continue;
                ans = max(ans, a[1][i] + a[2][j]);
            }
        }
        cout << ans << endl;
        return ;
    }

    int a1 = 0, b1 = 0, c1 = 0;
    for (int i = 1; i <= n; i ++){
        if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
            a[i][4] = 1;
            if (a[i][2] > a[i][3]){
                a[i][5] = 2;
                a[i][6] = 3;
            }
            else {
                a[i][5] = 3;
                a[i][6] = 2;
            }
            a1 ++;
            res[i].y = max(a[i][2], a[i][3]);
            res[i].z = min(a[i][2], a[i][3]);
        }
        else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
            a[i][4] = 2;
            if (a[i][1] > a[i][3]){
                a[i][5] = 1;
                a[i][6] = 3;
            }
            else {
                a[i][5] = 3;
                a[i][6] = 1;
            }
            b1 ++;
            res[i].y = max(a[i][1], a[i][3]);
            res[i].z = min(a[i][1], a[i][3]);
        } else{
            a[i][4] = 3;
            if (a[i][2] > a[i][1]){
                a[i][5] = 2;
                a[i][6] = 1;
            }
            else {
                a[i][5] = 1;
                a[i][6] = 2;
            }
            c1 ++;
            res[i].y = max(a[i][1], a[i][2]);
            res[i].z = min(a[i][1], a[i][2]);
        }

        res[i].x = a[i][a[i][4]];
    }

    int ans = 0;
    if (max(a1, max(b1, c1)) <= n / 2){
        for (int i = 1; i <= n; i ++){
            ans += res[i].x;
        }
        cout << ans << endl;
        return ;
    }

    sort(res + 1, res + n + 1, cmp);

    int sum, num;
    for (int i = 1; i <= n; i ++){
        ans += res[i].x;
        vis[a[i][4]] ++;
        if (vis[a[i][4]] > n / 2){
            sum = a[i][4];
            num = vis[a[i][4]];
        }
    }
    num -= n / 2;

    int cnt = 1;
    for (int i = 1; i <= n; i ++){
        if (a[i][4] == sum){
            bes[cnt] = res[i].x - res[i].y;
            cnt ++;
        }
    }

    sort(bes + 1, bes + cnt);

    for (int i = 1; i <= num; i ++){
        ans -= bes[i];
    }

    cout << ans << endl;

    return ;
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t --){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= 3; j ++){
                cin >> a[i][j];
            }
        }

        solve(n);

    }

    return 0;
}
