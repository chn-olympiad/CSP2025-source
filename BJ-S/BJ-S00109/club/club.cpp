#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, a[maxn][4];
vector<int> v[4];
long long ans;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t--){
        ans = 0;
        for(int i = 1; i <= 3; i++){
            v[i].clear();
        }
        cin >> n;
        for(int i = 1; i <= n; i++){
            int st = 0, nd = 0;
            a[i][0] = -1;
            for(int j = 1; j <= 3; j++){
                cin >> a[i][j];
            }
            for(int j = 1; j <= 3; j++){
                if(a[i][st] < a[i][j]){
                    st = j;
                }
            }
            for(int j = 1; j <= 3; j++){
                if((j != st) && (a[i][nd] < a[i][j])){
                    nd = j;
                }
            }
            ans += a[i][st];
            v[st].push_back(a[i][st] - a[i][nd]);
        }
        for(int i = 1; i <= 3; i++){
            if(v[i].size() > (n / 2)){
                sort(v[i].begin(), v[i].end());
                for(int j = 0; j < (v[i].size() - (n / 2)); j++){
                    ans -= v[i][j];
                }
                break;
            }
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
