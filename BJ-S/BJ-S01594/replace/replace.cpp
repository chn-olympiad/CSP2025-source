#include <bits/stdc++.h>
#define int long long
using namespace std;
int n = 0;
int q = 0;
static int im[26];
set <int> st;
const int mod1 = 998244353;
const int mod2 = 1000000009;
const int bs1 = 200011;
const int bs2 = 200037;
string s1[200010];
string s2[200010];
int dif1[200010];
int dif2[200010];
int pw1[5000010];
int pw2[5000010];
unordered_map <int, int > mp;
vector <int> ok[200010];
string t1 = "";
string t2 = "";
int hs11[5000010];
int hs12[5000010];
int hs21[5000010];
int hs22[5000010];
int h11[200010];
int h12[200010];
int h21[200010];
int h22[200010];
signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    im[0] = 1;
    im[1] = 2;
    for(int i = 2; i < 26; i++){
        im[i] = im[i - 1] + im[i - 2];
    } pw1[0] = 1; pw2[0] = 1;
    for(int i = 1; i <= 5000003; i++){
        pw1[i] = pw1[i - 1] * bs1 % mod1;
        pw2[i] = pw2[i - 1] * bs2 % mod2;
    } int tot = 0;
    for(int i = 1; i <= n; i++){
        cin >> s1[i] >> s2[i];
        int sum11 = 0; int sum12 = 0;
        int sum21 = 0; int sum22 = 0;
        for(int j = 0; j < s1[i].size(); j++){
            int dy = im[s1[i][j] - 'a'];
            sum11 += dy * pw1[j] % mod1; sum11 %= mod1;
            sum12 += dy * pw2[j] % mod2; sum12 %= mod2;
        } for(int j = 0; j < s2[i].size(); j++){
            int dy = im[s2[i][j] - 'a'];
            sum21 += dy * pw1[j] % mod1; sum21 %= mod1;
            sum22 += dy * pw2[j] % mod2; sum22 %= mod2;
        } dif1[i] = (sum11 + mod1 - sum21) % mod1;
        dif2[i] = (sum12 + mod2 - sum22) % mod2;
        int cb = dif2[i] * 1000000000ll + dif1[i];
        if(mp[cb] == 0){
            mp[cb] = ++ tot;
        } ok[mp[cb]].push_back(i);
        h11[i] = sum11; h12[i] = sum12; h21[i] = sum21; h22[i] = sum22;
    }
    while(q --){
        cin >> t1 >> t2;
        if(t1.size() != t2.size()){
            cout << 0 << '\n'; continue;
        } int len = t1.size();
        hs11[len] = 0; hs12[len] = 0;
        hs21[len] = 0; hs22[len] = 0;
        int as = 0; int pmx = 0;
        for(int i = 0; i < len; i++){
            pmx = i;
            if(t1[i] != t2[i]) break;
        }
        for(int i = len - 1; i >= 0; i--){
            hs11[i] = hs11[i + 1] * bs1 % mod1;
            hs11[i] = (hs11[i] + im[t1[i] - 'a']) % mod1;
            hs12[i] = hs12[i + 1] * bs2 % mod2;
            hs12[i] = (hs12[i] + im[t1[i] - 'a']) % mod2;
            hs21[i] = hs21[i + 1] * bs1 % mod1;
            hs21[i] = (hs21[i] + im[t2[i] - 'a']) % mod1;
            hs22[i] = hs22[i + 1] * bs2 % mod2;
            hs22[i] = (hs22[i] + im[t2[i] - 'a']) % mod2;
            if(i > pmx) continue;
            int df1 = (hs11[i] + mod1 - hs21[i]) % mod1;
            int df2 = (hs12[i] + mod2 - hs22[i]) % mod2;
            int cb = df2 * 1000000000ll + df1;
            if(!mp.count(cb)) continue;
            int qwq = mp[cb];
            for(int tt : ok[qwq]){
                int ln = s1[tt].size();
                if(i + ln - 1 >= len) continue;
                if(hs11[i + ln] != hs21[i + ln] || hs12[i + ln] != hs22[i + ln]) continue;
                if((hs11[i] + mod1 - (hs11[i + ln] * pw1[ln] % mod1)) % mod1 != h11[tt]) continue;
                if((hs12[i] + mod2 - (hs12[i + ln] * pw2[ln] % mod2)) % mod2 != h12[tt]) continue;
                if((hs21[i] + mod1 - (hs21[i + ln] * pw1[ln] % mod1)) % mod1 != h21[tt]) continue;
                if((hs22[i] + mod2 - (hs22[i + ln] * pw2[ln] % mod2)) % mod2 != h22[tt]) continue;
                as ++;
            }
        } cout << as << '\n';
    } return 0;
}