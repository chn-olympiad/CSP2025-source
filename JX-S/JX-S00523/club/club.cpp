#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005][5], ans, x[100005], A, k[5], ans1;
struct S{
    int l, num;
}y[100005];
bool f(S x, S w){
    return x.num > w.num;
}
void dfs(int t, int x, int y, int z, int s){
    if (t > n){
        ans = max(ans, s);
    }
    if (x + 1 <= n / 2){
        dfs(t + 1, x + 1, y, z, s + a[t][1]);
    }
    if (y + 1 <= n / 2){
        dfs(t + 1, x, y + 1, z, s + a[t][2]);
    }
    if (z + 1 <= n / 2){
        dfs(t + 1, x, y, z + 1, s + a[t][3]);
    }
}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t --){
        ans = 0, A = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= 3; j ++){
                cin >> a[i][j];
                if (j == 1)
                    x[i] = a[i][j];
                y[j].num = a[i][j];
                y[j].l = j;
            }
            if (a[i][2] == 0 && a[i][3] == 0) A ++;
            sort(y + 1, y + 4, f);
            if (k[y[1].l] + 1 <= n / 2){
                k[y[1].l] ++;
                ans1 += y[1].num;
                continue;
            }
            if (k[y[2].l] + 1 <= n / 2){
                k[y[2].l] ++;
                ans1 += y[2].num;
                continue;
            }
            if (k[y[3].l] + 1 <= n / 2){
                k[y[3].l] ++;
                ans1 += y[3].num;
                continue;
            }
        }
        if (A == n){
           sort(x + 1, x + 1 + n);
           for (int i = n; i > n / 2; i --){
                ans += x[i];
           }
           cout << ans << endl;
           continue;
        }
        if (n <= 10){
            dfs(1, 0, 0, 0, 0);
            cout << ans << endl;
        }
        else {
            cout << ans1 << endl;
        }
    }

    return 0;
}
