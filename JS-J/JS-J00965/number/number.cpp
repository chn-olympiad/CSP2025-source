/*
luogu uid: 1054383

exception: 100pts
*/

#include <bits/stdc++.h>

std::map<char, int> cnt;

int main() {
    std::freopen("number.in", "r", stdin);
    std::freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::string s;
    std::cin>>s;
    for(auto i : s) {
        if(isdigit(i)) cnt[i]++;
    }
    for(auto i(cnt.rbegin()); i!=cnt.rend(); i++) {
        for(int j(1); j<=i->second; j++) std::cout<<i->first;
    }
    std::cout<<"\n";
    return 0;
}