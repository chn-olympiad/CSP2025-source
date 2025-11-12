#include <bits/stdc++.h>
using namespace std;
int t, n, cnt[5];
pair<int, int> a[100005][5];
vector<int> v[5], now;
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        v[1].clear();
        v[2].clear();
        v[3].clear();
        now.clear();
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                cin >> a[i][j].first;
                a[i][j].second = j;
            }
            sort(a[i] + 1, a[i] + 3 + 1);
            ans = ans + a[i][3].first;
            cnt[a[i][3].second]++;
            v[a[i][3].second].push_back(i);
        }
        for(int j = 1;j <= 3;j++){
            if(cnt[j] > n / 2){
                for(int i = 0;i < (int)v[j].size();i++){
                    int my = v[j][i];
                    now.push_back(a[my][3].first - a[my][2].first);
                }
                sort(now.begin(), now.end());
                for(int i = 0;i < cnt[j] - n / 2;i++){
                    ans -= now[i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
