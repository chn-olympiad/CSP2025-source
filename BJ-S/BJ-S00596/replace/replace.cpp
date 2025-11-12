#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
map<pii, int> mp;
int n, q;
const int Mod = 1e9 + 9;
inline int trans(char ch){
    if(ch == 'z') return 29;
    if(ch == 'y') return 28;
    if(ch == 'c') return 27;
    return ch - 'a' + 1;
}
inline int Hashs(string s){
    int res = 0;
    for(int i = 0; i < (int)s.length(); i++){
        res = res * 31 + trans(s[i]);
        res %= Mod;
    }
    return res;
}
inline int fp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}
int qianzs1[2000005], qianzs2[2000005];
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1 == s2) continue;
        mp[make_pair(Hashs(s1), Hashs(s2))]++;
    }
    while(q--){
        string s1, s2;
        cin >> s1 >> s2;
        if(s1.length() != s2.length()){
            cout << 0 << '\n';
            continue;
        }
        for(int i = 1; i <= (int)s1.length(); i++) qianzs1[i] = (qianzs1[i - 1] * 31 + trans(s1[i - 1])) % Mod;
        for(int i = 1; i <= (int)s2.length(); i++) qianzs2[i] = (qianzs2[i - 1] * 31 + trans(s2[i - 1])) % Mod;
        int firstdif, lastdif;
        for(int i = 1; i <= (int)s1.length(); i++){
            if(s1[i - 1] != s2[i - 1]){
                firstdif = i;
                break;
            }
        }
        for(int i = (int)s1.length(); i >= 1; i--){
            if(s1[i - 1] != s2[i - 1]){
                lastdif = i;
                break;
            }
        }
        int ans = 0;
        for(int l = 1; l <= firstdif; l++){
            for(int r = lastdif; r <= (int)s1.length(); r++){
                ans += mp[make_pair(((qianzs1[r] - qianzs1[l - 1] * fp(31, r - l + 1)) % Mod + Mod) % Mod, ((qianzs2[r] - qianzs2[l - 1] * fp(31, r - l + 1)) % Mod + Mod) % Mod)];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}