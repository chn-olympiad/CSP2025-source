#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 210;
int n;
int a[N][3], t[N];
int f[M][M][M];
struct ppl{
    int gua, id;
    bool operator < (ppl t){
        return gua < t.gua;
    }
}ps[N];
int run1(){
    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int x = 0; x <= i; x++)    
            for (int y = 0; y <= i - x; y++){
                if (x)f[i][x][y] = max(f[i][x][y], f[i-1][x-1][y] + a[i][0]);
                if (y)f[i][x][y] = max(f[i][x][y], f[i-1][x][y-1] + a[i][1]);
                if (x + y <= i - 1)f[i][x][y] = max(f[i][x][y], f[i-1][x][y] + a[i][2]);
                // cout << i << ' ' << x << ' ' << y << ' ' << f[i][x][y] << endl;
            }
    int ans = 0;
    for (int i = 0; i <= n / 2; i++)
        for (int j = 0; j <= n - i; j++)
            if (max(max(i, j), n - i - j) <= n / 2)
                ans = max(ans, f[n][i][j]);
    return ans;
}
void run(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    if (n <= 200){
        cout << run1() << endl;
        return;
    }
    int A = 1, B = 1;
    for (int i = 1; i <= n; i++){   
        if (a[i][1])A = 0;
        if (a[i][2])B = 0;
    }
    if (A && B){
        for (int i = 1; i <= n; i++)t[i] = a[i][0];
        sort(t + 1, t + n + 1);
        int ans = 0;
        for (int i = 1; i <= n / 2; i++)
            ans += t[i];
        cout << ans << endl;
        return;
    }
    if (B){
        for (int i = 1; i <= n; i++)
            ps[i] = {min(a[i][0], a[i][1]) - max(a[i][0], a[i][1]), i};
        sort(ps + 1, ps + n + 1);
        int c0 = 0, c1 = 0, ans = 0;
        for (int i = 1; i <= n; i++){
            int id = ps[i].id;
            int mx = 0;
            if (a[i][1] > a[i][0])mx = 1;
            if (a[i][1] == a[i][0]){
                if (c0 < c1)mx = 0;
                else mx = 1;
            }
            if (c0 == n / 2)mx = 1;
            if (c1 == n / 2)mx = 0;
            if (mx == 0)ans += a[i][0], c0++;
            if (mx == 1)ans += a[i][1], c1++;
        }
        cout << ans << endl;
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += max(a[i][0], max(a[i][1], a[i][2]));
    cout << ans << endl;
}
int main(){
    freopen("club.in", "r", stdin);    
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        run(); 
    return 0;
}