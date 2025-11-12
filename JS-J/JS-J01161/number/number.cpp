//2025CSP-J/S rp++
//please be a nice score!
#include <bits/stdc++.h>
using namespace std;

int cnt[256];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    memset(cnt, 0, sizeof(cnt));
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        cnt[(int)(s[i])]++;
    }
    for(int i = (int)('9');i >= (int)('0');i--){
        for(int j = 1;j <= cnt[i];j++){
            cout << (char)(i);
        }
    }
    cout << "\n";
    return 0;
}
