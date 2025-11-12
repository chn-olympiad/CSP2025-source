#include <bits/stdc++.h>
using namespace std;
struct member {
    int name;
    int s;
    int b;
};
member a[300300];
bool cmp (member a, member y){
    if (a.s == y.s) return a.b < y.b;
    else if (a.s == y.s && a.b == y.b) return a.name < y.name;
    return a.s > y.s;
}
long long ans = 0;
int w[4] = {0};
bool used[100100];
int main (){
    freopen ("club.in", "r", stdin);
    freopen ("club.out", "w", stdout);
    int t;
    cin >> t;
    while (t--){
        for (int i = 0; i <= 100100; i++) used[i] = true;
        for (int i = 0; i <= 4; i++) w[i] = 0;
        ans = 0;
        int n, n3;
        cin >> n3;
        int hn = n3 / 2;
        n = n3 * 3;
        for (int i = 1; i <= n; i++){
            cin >> a[i].s;
            a[i].b = (i - 1) % 3 + 1;
            a[i].name = (i - 1) / 3 + 1;
        }
        sort (a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++){
            int ls = a[i].b;
            int la = a[i].name;
            if (w[ls] <= hn && used[la]){//
                used[la] = false;
                w[ls]++;
                ans += a[i].s;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
