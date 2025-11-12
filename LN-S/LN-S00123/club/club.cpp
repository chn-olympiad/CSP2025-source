#include <bits/stdc++.h>
using ll = long long;
#define int ll
constexpr int N = 100005;
int a[N][3];
std::vector < int > vec[3];
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t; std::cin >> t;
    while (t--){
        int ans = 0;
        for (int i = 0; i < 3; i++){
            vec[i].clear();
        }
        memset(a, 0, sizeof a);
        int n; std::cin >> n;
        for (int i = 1; i <= n; i++){
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
                vec[0].push_back(i);
                ans += a[i][0];
            }
            else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
                vec[1].push_back(i);
                ans += a[i][1];
            }
            else if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]){
                vec[2].push_back(i);
                ans += a[i][2];
            }
        }
        for (int i = 0; i < 3; i++){
            if (vec[i].size() > n / 2){
                std::vector < int > tmp;
                for (int j = 0; j < vec[i].size(); j++){
                    tmp.push_back(std::min(a[vec[i][j]][i] - a[vec[i][j]][(i + 1) % 3], a[vec[i][j]][i] - a[vec[i][j]][(i - 1 + 3) % 3]));
                }
                std::sort(tmp.begin(), tmp.end());
                for (int j = 1; j <= vec[i].size() - n / 2; j++)
                    ans -= tmp[j - 1];
            }
        }
        std::cout << ans << std::endl;
    }
}