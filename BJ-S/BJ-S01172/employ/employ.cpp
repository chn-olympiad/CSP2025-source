#include <bits/stdc++.h>
using namespace std;
const int N = 500 +10;
const int MOD = 998244353;
int a[N];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0;
    string s;
    cin >>n >> m >> s;
    for(int i = 1; i <= n; i++) {
        cin >>a[i];
        if(a[i]) cnt++; //1
    }
    int cnt2 = n - cnt; //0
    if(cnt < m) {
        cout <<0;
        return 0;
    }
    else{

        long long ans = 1;
        for(int i = 0;i < m; i++){
            ans = ans * (cnt - i) % MOD;
        }
        for(int i = 1; i <= m; i++)
                ans /= i;
        for(int i = 1; i <= n-m; i++)
            ans = (ans * i) %MOD;
    cout <<ans;
    }
}
