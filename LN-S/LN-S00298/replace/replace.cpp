#include<bits/stdc++.h>
using namespace std;
namespace Aurora{ void Main(); }
int main(){ return Aurora::Main(), 0; }
namespace Aurora{
    #define ll long long
    const int N = 2e5 + 5, L = 5e6 + 5;
    const int base1 = 1145141, base2 = 131, mod1 = 998244353, mod2 = 1e9 + 7;
    int n, q, len[N];
    ll hash1[N], hash2[N];
    string s1[N], s2[N], h1, h2, nh;
    bool flag[N];
    map<ll, ll> buf1, buf2;
    void Calc(int x, int l, int r){
        for(int i = l; i <= r; i++){
            int now = s1[x][i] - 'a';
            hash1[x] = 1ll * hash1[x] * base1 % mod1 + now;
            hash2[x] = 1ll * hash2[x] * base2 % mod2 + now;
        }
        for(int i = l; i <= r; i++){
            int now = s2[x][i] - 'a';
            hash1[x] = 1ll * hash1[x] * base1 % mod1 + now;
            hash2[x] = 1ll * hash2[x] * base2 % mod2 + now;
        }
        hash1[x] %= mod1; hash2[x] %= mod2;
        buf1[hash1[x]]++;
        buf2[hash2[x]]++;
    }
    ll h1s1[N], h1s2[N], h2s1[N], h2s2[N];
    void Solve1(){
        for(int i = 1; i <= n; i++){
            cin >> s1[i] >> s2[i];
        }
        while(q--){
            cin >> h1 >> h2;
            int l = h1.length();
            int ans = 0;
            for(int i = 0; i < l; i++){
                for(int j = 1; j <= n; j++){
                    bool ok = 1;
                    int len = s1[j].length();
                    if(i + len - 1 > n) continue;
                    for(int k = 0; k < l; k++) nh[k] = h1[k];
                    for(int k = i; k <= i + len - 1; k++){
                        if(h1[k] != s1[j][k - i]){ 
                            ok = 0; break; 
                        }else nh[k] = s2[j][k - i];
                    }
                    // cout << i << " " << j << " " << ok << endl;
                    if(ok == 1){
                        for(int k = 0; k < l; k++) if(nh[k] != h2[k]){
                            ok = 0; break;
                        }
                    }
                    if(ok) ans++;
                }
            }
            cout << ans << "\n";
        }
    }
    void Solve2(){
        for(int i = 1; i <= n; i++){
            cin >> s1[i] >> s2[i];
            // scanf("%s%s", s1[i], s2[i]); 
            len[i] = s1[i].length();
            // cout << s1[i] << " " << s2[i] << endl;
            int lp = 0, rp = len[i] - 1;
            while(lp <= len[i] - 1 && s1[i][lp] == s2[i][lp]) lp++;
            while(rp >= 0 && s1[i][rp] == s2[i][rp]) rp--;
            if(rp < lp) flag[i] = 1;
            else Calc(i, lp, rp);
        }
        // return;
        while(q--){
           cin >> h1 >> h2; int l = h1.length();

            int lp = 0, rp = l - 1;
            while(lp <= l - 1 && h1[lp] == h2[lp]) lp++;
            while(rp >= 0 && h1[rp] == h2[rp]) rp--;

            ll f1 = 0, f2 = 0;
            for(int i = lp; i <= rp; i++){
                int now = h1[i] - 'a';
                f1 = 1ll * f1 * base1 % mod1 + now;
                f2 = 1ll * f2 * base2 % mod2 + now;
            }
            for(int i = lp; i <= rp; i++){
                int now = h2[i] - 'a';
                f1 = 1ll * f1 * base1 % mod1 + now;
                f2 = 1ll * f2 * base2 % mod2 + now;
            }
            f1 %= mod1, f2 %= mod2;
            int ans = min(buf1[f1], buf2[f2]);
            cout << ans << "\n";
        }
    }
    void Main(){
        freopen("replace.in", "r", stdin);
        freopen("replace.out", "w", stdout);
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cin >> n >> q;
        if(n <= 100) Solve1();
        else if(n >= 100) Solve2();
    }
}