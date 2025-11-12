#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, m;
string s;
int c[1005];
long long jiec(long long n){
    long long ans = 1;
    for(long long i = 2; i <= n; i++)
        ans = (ans * i) % mod;
    return ans;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    cin >> s;
    bool f = 1;
    for(int i = 1; i <= n; i++)
            cin >> c[i];
    for(int i = 0; i < s.size(); i++)
            if(s[i] == 0) f = 0;
    if(f){
            int cnt=0;
        for(int i = 1; i <= n; i++){
            if(c[i] == 0) cnt++;
        }
        if(n - cnt < m) cout << 0;
        else cout << jiec(n);
    }
}
