#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[15];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    if(s.size() == 1){
        cout << s[0];
        return 0;
    }
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            cnt[ll(s[i]) - 48]++;
        }
    }
    bool flag = false;
    for(int i = 9; i > 0; i--){
        if(cnt[i] == 0) continue;
        else flag = true;
        for(int j = 1; j <= cnt[i]; j++){
            cout << i;
        }
    }
    if(!flag){
        cout << 0;
        return 0;
    }else{
        for(int j = 1; j <= cnt[0]; j++){
            cout << 0;
        }
    }
    return 0;
}


