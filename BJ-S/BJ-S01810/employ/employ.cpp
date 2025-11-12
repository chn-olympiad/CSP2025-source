#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500;
const int mod = 998244353;
int n, m;
int c[N];

int j(int x){
    int res = 1;
    for(int i = 2; i <= x; i++)
        res *= i;
    return res;
}

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    string s;
    cin >> s;
    int cc = 0;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(c[i] == 0)
            cc++;
    }
    if(cc == 0)
        cout << j(n) % mod / (j(n - m) % mod);
    else
        cout << j(n - 1) % mod / (j(n - 1 - m) % mod);
    return 0;
}
