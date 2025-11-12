#include <bits/stdc++.h>
using namespace std;
int n, m, ans, fail, dif[500], c[500], order[500];
bool isorder[500];
string s;
bool check(){
    int sum = n;
    for (int i = 1;i <= n;i++){
        if (fail >= c[i]){
            if (sum < m) return false;
            else sum--;
        }
    }
    return true;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    for (int i = 1;i <= n;i++){
        cin >> c[i];
    }
    for (int i = 1;i <= s.length();i++){
        dif[i] = s[i-1];
    }
    for (int i = 1;i <= n;i++){
        order[i] = i;
        if (dif[i] == 0) fail++;
    }
    if (check()) ans++;
    for (int i = n;i >= 1;i--){
        order[i] = i;
        if (dif[i] == 0) fail++;
    }
    if (check()) ans++;
    cout << ans % 998244353 << endl;
    return 0;
}