#include <bits/stdc++.h>
using namespace std;
long long ch[11] = {0};
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(auto c : s){
        if(c >= '0' && c <= '9') ch[c - '0']++;
    }
    for(int i = 9; i >= 0; i--){
        for(int j = ch[i]; j > 0; j--){
            cout << i;
        }
    }
    cout << endl;
}
