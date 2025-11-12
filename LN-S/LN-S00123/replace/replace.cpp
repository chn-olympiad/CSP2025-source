#include <bits/stdc++.h>
using ll = long long;
std::map < std::string, std::string > mp;
std::string table[2005][2005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q; std::cin >> n >> q;
    for (int i = 1; i <= n; i++){
        std::string s, t; std::cin >> s >> t;
        mp[s] = t;
    }
    while (q--){
        int ans = 0;
        std::string x, y; std::cin >> x >> y;
        if (x.size() != y.size()){
            std::cout << 0 << std::endl;
            continue;
        }
        int m = x.size();
        x = '?' + x;
        y = '?' + y;
        for (int i = 1; i <= m; i++){
            std::string t;
            for (int j = i; j <= m; j++){
                t += x[j];
                table[i][j] = t;
            }
        }
        for (int i = 1; i <= m; i++){
            std::string t;
            for (int j = i; j <= m; j++){
                t += x[j];
                if (mp.count(t)){
                    std::string s = mp[t];
                    if ('?' + table[1][i - 1] + s + table[j + 1][m] == y)
                        ans++;
                }
            }
        }
        std::cout << ans << std::endl;
    }
}