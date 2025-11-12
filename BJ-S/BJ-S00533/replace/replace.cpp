#include<bits/stdc++.h>
#define int long long
int n, m;
std::map<std::string, std::string> ms;
std::string x, y;
signed main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y;
        ms[x] = y;
    }
    while(m--) {
        int ans = 0;
        std::cin >> x >> y;
        for(auto p : ms) {
            int pos = -1;
            std::string f1 = p.first, f2 = p.second;
            while((pos = x.find(f1, pos + 1)) != std::string::npos) {
                x.replace(pos, f1.size(), f2);
                if(x == y) ans++;
                x.replace(pos, f2.size(), f1);
            }
        }
        std::cout << ans << "\n";
    }
}
