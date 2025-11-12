#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int m, n;
string s;
int a[505];
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    int nn = n;
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 0) nn--;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            flag = 0;
            break;
        }
    }
    if(nn < m){
        cout << 0;
        return 0;
    }
    if(flag){
        int mul = 1;
        for(int i = 1; i <= nn; i++){
            mul = mul * i % mod;
        }
        cout << mul;
    }else if(m == n) cout << 0;
    cout << 0;
    return 0;
}
