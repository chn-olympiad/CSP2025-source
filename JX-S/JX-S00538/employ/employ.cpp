#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510, mod = 998244353;
int n, m, s[N], c[N], res, p[N], ss[N];
ll jc, f[N];
void add(ll &x, ll y){
    x += y;
    if(x >= mod)x -= mod;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    bool fl = 1;
    jc = 1;
    for(int i = 1; i <= n; i ++){
        jc = jc * i % mod;
        char c;
        cin >> c;
        s[i] = c - '0';
        ss[i] = s[i];
        ss[i] += ss[i - 1];
    }
    for(int i = 1; i <= n; i ++){
        cin >> c[i];
    }
    if(n <= 10){
        int res = 0;
        for(int i = 1; i <= n; i ++)p[i] = i;
        do{
            int cnt = 0, ch = 0;
            for(int i = 1; i <= n; i ++){
                int x = p[i];
                if(cnt >= c[x])cnt ++;
                else if(s[i])ch ++;
                else cnt ++;
            }
            if(ch >= m)res ++;
        }while(next_permutation(p + 1, p + 1 + n));
        cout << res;
        return 0;
    }
    if(m == 1){
        int mi = n;
        for(int i = 1; i <= n; i ++){
            mi = min(mi, c[i]);
        }
        if(mi != 1){
            cout << jc;
            return 0;
        }
        for(int i = 1; i <= n; i ++){
            c[i] = lower_bound(ss + 1, ss + 1 + n, c[i]) - ss;
        }
        sort(c + 1, c + 1 + n);
        int res = 0;
        f[n] = 1;
        for(int i = n - 1; i >= 1; i --){
            add(f[i], f[i + 1] * (n - c[i + 1] + 1 - (n - i) + c[i + 1] - c[i]) % mod);
        }
        cout << (jc - f[1] + mod) % mod;
        return 0;
    }
    return 0;
}