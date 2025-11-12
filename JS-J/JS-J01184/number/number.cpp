#include <bits/stdc++.h>
using namespace std;
int cnt[15] = {};
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0;i < s.size();i++){
        if ('0' <= s[i] && s[i] <= '9'){
            cnt[s[i] - 48]++;
        }
    }
    for (int i = 9;i > -1;i--){
        for (int j = 0;j < cnt[i];j++){
            cout << i;
        }
    }
    return 0;
}
