#include<bits/stdc++.h>
using namespace std;
string s, k[15];
int f;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            k[s[i]-'0'] += s[i];
        }
    }
    for (int i = 9; i >= 0; i --){
        if (k[i].size() == 0) f ++;
        if (i == 0 && f == 9 && k[i].size() != 0) cout << '0';
        else cout << k[i];
    }

    return 0;
}
