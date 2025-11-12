#include<bits/stdc++.h>
using namespace std;

string s;

bool cmp(int a, int b){
    return a > b;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;

    int n = s.size();
    vector<int> num;
    for(int i = 0; i < n; i++){
        if('0' <= s[i] && s[i] <= '9') num.push_back(s[i] - '0');
    } 

    sort(num.begin(), num.end(), cmp);

    for(const auto &c : num) cout << c;
    cout << "\n";

    return 0;
}


// Kasty's code