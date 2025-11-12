#include<bits/stdc++.h>
using namespace std;
string s, ans = "";
long long sum[11];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int n = s.size();
    for (int i = 0;i < n;++ i){
        if (s[i] >= '0'&&s[i] <= '9'){
            sum[s[i] - '0'] ++;
        }
    }
    for (int i = 9;i >= 0;-- i){
        if (i == 0&&ans == ""){
            ans = '0';
            break;
        }
        if (sum[i] != 0){
            for (int j = 1;j <= sum[i];++ j){
                ans += to_string(i);
            }
        }
    }
    cout << ans;
    return 0;
}
