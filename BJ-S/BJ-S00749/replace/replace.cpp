#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 200005;
const LL BAS = 29;
const LL MOD = 1e9 + 7;
LL n, Q; LL pw[MAXN], hsh1[MAXN], hsh2[MAXN], hshh1[MAXN], hshh2[MAXN], lenn[MAXN];
void InitHash(LL id, string s, string t)
{
    for(LL i = 0; i < s.length(); i ++) hsh1[id] = (hsh1[id] * BAS % MOD + (s[i] - 'a' + 1)) % MOD;
    for(LL i = 0; i < t.length(); i ++) hsh2[id] = (hsh2[id] * BAS % MOD + (t[i] - 'a' + 1)) % MOD;
    return;
}
void InitHash2(string s, string t)
{
    for(LL i = 1; i < s.length(); i ++) hshh1[i] = (hshh1[i - 1] * BAS % MOD + (s[i] - 'a' + 1)) % MOD;
    for(LL i = 1; i < t.length(); i ++) hshh2[i] = (hshh2[i - 1] * BAS % MOD + (t[i] - 'a' + 1)) % MOD;
    return;
}
LL GetHash(LL id, LL L, LL R)
{
    if(L > R) return 0;
    if(id == 1) return ((hshh1[R] - (hshh1[L - 1] * pw[R - L + 1] % MOD)) % MOD + MOD) % MOD;
    else return ((hshh2[R] - (hshh2[L - 1] * pw[R - L + 1] % MOD)) % MOD + MOD) % MOD;
}
int main()
{
    freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> Q; pw[0] = 1; for(LL i = 1; i < MAXN; i ++) pw[i] = (pw[i - 1] * BAS) % MOD;
    for(LL i = 1; i <= n; i ++) { string s1, s2; cin >> s1 >> s2; InitHash(i, s1, s2); lenn[i] = s1.length(); }
    if(n <= 100 && Q <= 100)
    {
        while(Q --)
        {
            string s1, s2; cin >> s1 >> s2; s1 = " " + s1; s2 = " " + s2; InitHash2(s1, s2);
            LL ans = 0;
            LL len1 = s1.length(), len2 = s2.length();
            if(len1 != len2) { cout << 0 << '\n'; continue; }
            for(LL L = 1; L < len1; L ++)
            {
                for(LL R = L; R < len2; R ++)
                {
                    for(LL i = 1; i <= n; i ++)
                    {
                        if(R - L + 1 != lenn[i]) continue;
                        if(GetHash(1, L, R) != hsh1[i]) continue;
                        if(GetHash(2, L, R) != hsh2[i]) continue;
                        if(GetHash(1, 1, L - 1) != GetHash(2, 1, L - 1)) continue;
                        if(GetHash(1, R + 1, len1 - 1) != GetHash(2, R + 1, len2 - 1)) continue;
                        ans ++;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    else
    {
        while(Q --)
        {
            string s1, s2; cin >> s1 >> s2;
            cout << 0 << '\n';
        }
    }
    return 0;
}
