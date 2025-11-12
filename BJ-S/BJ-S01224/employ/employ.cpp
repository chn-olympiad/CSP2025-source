#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long ksm(long long a,int n){
    long long ans = 1;
    while(n){
        if(n & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
int n,m,c[505];
string s;
long long ans,jc[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    if(n == m){
        s = ' ' + s;
        jc[0] = jc[1] = 1;
        for(int i = 2;i <= n;i++){
            jc[i] = jc[i - 1] * i % mod;
        }
        for(int i = 1;i <= n;i++){
            cin >> c[i];
            if(!c[i] || s[i] == '0'){
                cout << 0;
                return 0;
            }
        }
        cout << jc[n];
        return 0;
    }
    s = ' ' + s;
    jc[0] = jc[1] = 1;
    for(int i = 2;i <= n;i++){
        jc[i] = jc[i - 1] * i % mod;
    }
    for(int i = 1;i <= n;i++){
        int tmp;
        cin >> tmp;
        c[tmp]++;
    }
    long long ans = 1;
    for(int i = 1;i <= n;i++){
        c[i] += c[i - 1];
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(s[i] == '0'){
            cnt++;
        }else{
            ans = ans * (c[i - 1] - (i - 1 - cnt)) % mod;
        }
    }
    ans *= jc[cnt];
    ans %= mod;
    cout << (jc[n] - ans + mod) % mod;
    return 0;
}
