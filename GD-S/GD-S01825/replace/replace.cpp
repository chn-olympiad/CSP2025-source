#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
const int MAX = 2e5 + 5;
const int bash = 1331;

int n,q;
std::string sa[MAX],sb[MAX];
std::vector<int> pi[MAX];
ull num[MAX];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    std::cin.tie(0) -> sync_with_stdio(0);

    std::cin >> n >> q;
    for(int i = 1;i <= n;i++){
        std::cin >> sa[i] >> sb[i];
        num[i] = 1;
        for(auto ch : sb[i]){
            num[i] *= bash;
            num[i] += bash * ch;
        }
        auto GetPi = [&](std::string &s,std::vector<int> &p)
        {
            for(int j = 0,i = 1;i < s.size();i++){
                while(j && s[j] != s[i]) j = p[p[i - 1]];
                if(s[j] == s[i]) j++;
                p[i] = j++;
            }
        };
        pi[i].resize(sa[i].size());
        GetPi(sa[i],pi[i]);
    }
    for(int i = 1;i <= n;i++){
        for(auto j : pi[i])
            std::cout << j << ' ';
        std::cout << '\n';
    }
    return 0;
}