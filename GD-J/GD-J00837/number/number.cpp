#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;;
    cin >>s;
    int zf[110] = { };
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            zf[s[i] - '0']++;
        }
    }
    bool fl = false; //jian ce shi fou zhi you 0
    for(int i = 0; i <= 9; i++) {
        if(i != 0 && zf[i] != 0) {
            fl = true; break;
        }
    }
    if(fl == false) {
        cout <<"0";
    }
    else {
        for(int i = 9; i >= 0; i--) {
            for(int j = 1; j <= zf[i]; j++) {
                cout <<i;
            }
        }
    }
    return 0;
}

