#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N][4] , n;
priority_queue <int , vector <int> , greater <int> > q[4];
int main(){
    freopen("club.in" , "r" , stdin);
    freopen("club.out" , "w" , stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int cases;
    cin >> cases;
    while (cases--){
        cin >> n;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= 3;j++) cin >> a[i][j];
        }
        int maxn , minn;
        ll ans = 0;
        for (int i = 1;i <= n;i++){
            maxn = 0;
            for (int j = 1;j <= 3;j++) maxn = max(maxn , a[i][j]);
            ans += maxn;
            for (int j = 1;j <= 3;j++){
                if (a[i][j] == maxn){
                    minn = 1e9;
                    for (int k = 1;k <= 3;k++){
                        if (k != j) minn = min(minn , a[i][j] - a[i][k]);
                    }
                    q[j].push(minn);
                }
            }
        }
        // cout << ans << ' ' << q[1].size() << ' ' << q[2].size() << ' ' << q[3].size() << '\n';
        for (int i = 1;i <= 3;i++){
            while (q[i].size() > n / 2){
                ans -= q[i].top();
                q[i].pop();
            }
        }
        cout << ans << '\n';
        for (int i = 1;i <= 3;i++){
            while (!q[i].empty()) q[i].pop();
        }
    }
    return 0;
}