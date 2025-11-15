#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long mod = 998244353;
int main(){

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    
    int c[n];
    char s[n];
    for(int x=0; x<n; x++) cin >> s[x];
    for(int x=0; x<n; x++) cin >> c[x];

    int all1 = 1;
    for(int x=0; x<n; x++){
        all1 = min(all1, s[x] - '0');
    }
    ll out = 0;
    if(all1 == 1){
        out = 1;
        for(ll x=n; x>=1; x--){
            out *= x;
            out %= mod;
        }
        cout << out << endl;
        return 0;
    }


    cout << out << endl;

    //10! = 3628800
}