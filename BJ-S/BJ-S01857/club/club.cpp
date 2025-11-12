#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int T , n , a[N][5];
bool A = 1 , B = 1 , C = 1;
void Init() {
    memset(a , 0 , sizeof(a));
}
namespace Work1 {
    int ans = -2e9;
    void DFS(int step , int x , int y , int z , int sum) {
        if(step > n) {
            ans = max(ans , sum);
            return;
        }
        if(x + 1 <= n / 2) DFS(step + 1 , x + 1 , y , z , sum + a[step][1]);
        if(y + 1 <= n / 2) DFS(step + 1 , x , y + 1 , z , sum + a[step][2]);
        if(z + 1 <= n / 2) DFS(step + 1 , x , y , z + 1 , sum + a[step][3]);
    }
    void Solve() {
        ans = -2e9;
        DFS(1 , 0 , 0 , 0 , 0);
        cout << ans << endl;
    }
}
namespace WorkB {
    int x[N];
    void Solve() {
        for(int i = 1;i <= n;i++) x[i] = a[i][1];
        sort(x + 1 , x + n + 1);
        int ans = 0;
        for(int i = 1;i <= n / 2;i++) ans += x[i];
        cout << ans << endl;
    }
}
int main() {
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            if(a[i][2] != 0 || a[i][3] != 0) B = 0;
        }
        if(n <= 10) Work1::Solve();
        if(B) WorkB::Solve();
    }
    return 0;
}