#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][3], b[N], n, T;
vector<int>pos[3];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        int ans = 0;
        pos[0].clear(), pos[1].clear(), pos[2].clear();
        for(int i = 1;i <= n;i++){
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            int mx = 0;
            for(int j = 1;j <= 2;j++){
                if(a[i][j] > a[i][mx])mx = j;
            }
            ans += a[i][mx];
            int mx1 = 0;
            for(int j = 0;j <= 2;j++){
                if(j == mx)continue;    
                mx1 = max(mx1, a[i][j]);
            }
            pos[mx].push_back(a[i][mx] - mx1);
        }
        for(int i = 0;i < 3;i++){
            if(pos[i].size() > n / 2){
                // cout << "find " << i << "\n";
                int ex = pos[i].size() - n / 2;
                sort(pos[i].begin(), pos[i].end());
                for(int j = 0;j < ex;j++){
                    ans -= pos[i][j];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}