#include <bits/stdc++.h>
using namespace std;
string s;
vector <int> a;

int cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] <= '9' && s[i] >= '0') a.push_back(s[i] - '0');
    }
    sort(a.begin(), a.end(), cmp);
    for (auto i : a) cout << i;
    return 0;
}

