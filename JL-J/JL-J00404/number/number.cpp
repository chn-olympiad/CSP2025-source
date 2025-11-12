#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int n = s.size();
    for (int i = 0;i < n;i ++){
        if (s[i] >= '0' && s[i] <= '9'){
            a[i] = s[i] - '0' + 1;
        }
    }
    sort(a, a + n);
    for (int i = n - 1;i > -1;i --){
        if (a[i] == 0) continue;
        if (a[i] == 1 && i == n - 1){
            cout << 0;
            return 0;
        }
        cout << a[i] - 1;
    }
    return 0;
}
