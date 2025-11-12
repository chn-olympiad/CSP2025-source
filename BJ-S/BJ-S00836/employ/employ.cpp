#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 509;
const ll mod = 998244353;
int n, m, cnt, kkk; ll ans;
string temp;
int s[N], c[N];
ll fac[N];
inline void init(){
    fac[0] = 1;
    for(int i=1; i<N; ++i)
    fac[i] = fac[i-1] * i % mod;
}
inline void solve1(){
    int p[20];
    for(int i=1; i<=n; ++i) p[i] = i;
    do{
        int now = 0, res = 0;
        for(int i=1; i<=n; ++i){
            if(!s[i]){
                ++now;
                continue;
            }if(now>=c[p[i]]){
                ++now;
            }else ++res;
        }if(res>=m) ++ans, ans %= mod;
    }while(next_permutation(p+1, p+n+1));
    cout << ans << endl;
}
inline void solve2(){
    sort(c+1, c+n+1); ans = 1;
    int now = 0, cnt0 = 0;
    for(int i=1; i<=n; ++i){
        if(!s[i]) continue;
        while(now<n && i-1>=c[now+1]) ++now;
        (ans *= (now-cnt0)) %= mod;
        ++cnt0;
    }(ans *= fac[n-cnt]) %= mod;
    ans = fac[n] - ans;
    ans %= mod;
    ans += mod;
    ans %= mod;
    cout << ans << endl;
}
int main(){ init();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> temp;
    for(int i=0; i<n; ++i){
        s[i+1] = (temp[i]=='1');
        cnt += s[i+1];
    }
    for(int i=1; i<=n; ++i){
        cin >> c[i];
        if(c[i]==0) kkk = 1;
    }
    if(cnt==n){
        cout << fac[n] << endl;
        return 0;
    }
    if(n<=10){
        solve1();
        return 0;
    }
    if(m==1){
        solve2();
        return 0;
    }
    if(m==n){
        if(cnt==n && kkk) cout << fac[n] << endl;
        else cout << 0 << endl;
        return 0;
    }
return 0;}