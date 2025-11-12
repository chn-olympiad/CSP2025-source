#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000050;
string s;
int num[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int cnt = 1;
    for(int i = 0; i < s.length(); i++){
        if('0' <= int(s[i]) && '9' >= int(s[i])){
            num[cnt] = int(s[i]) - 48;
            cnt++;
        }
    }
    sort(num + 1, num + cnt);
    for(int i = cnt - 1; i >= 1 ; i--){
        cout << num[i];
    }





    return 0;
}
