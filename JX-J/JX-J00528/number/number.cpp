#include <iostream>
using namespace std;
string s;
const int N = 15;
int cnt[N];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0;i < s.length();i++){
        char c = s[i];
        if('0' <= c && c <= '9'){
            cnt[c - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--){
        for(int k = 1;k <= cnt[i];k++){
            cout << i;
        }
    }
    return 0;
}
