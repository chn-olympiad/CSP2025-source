#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
const int MAX = 2e5 + 5;
const int bash = 1331;

int n,m,c[MAX];
std::string s;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> m;
    std::cin >> s;
    for(int i = 0;i < n;i++)
        std::cin >> c[i];
    std::sort(c,c + n);
    int ans = 0;
    do{
        int cnt = 0,sum = 0;
        for(int i = 0;i < n;i++){
            if(cnt >= c[i]){
                cnt++;
                continue;
            }
            if(s[i] == '1') sum++;
            else cnt++;
        }
        if(sum >= m) ans++;
    } while (std::next_permutation(c + 1,c + n + 1));
    std::cout << ans << '\n';
    return 0;
}