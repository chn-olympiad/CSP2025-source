#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second 
#define pb push_back 
#define mk make_pair 
#define db double 
using namespace std;
const int MAXN = 1e6 + 5, INF = 1e18, base = 131, mod = 998244353;

int n, q, ans;
char s[2][MAXN], T[2][MAXN];
int H0[MAXN], H1[MAXN], len[MAXN], pw[MAXN], Hash0[MAXN], Hash1[MAXN];

int check0(int l, int r) {
    return ((Hash0[r] - Hash0[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
}

int check1(int l, int r) {
    return ((Hash1[r] - Hash1[l - 1] * pw[r - l + 1] % mod) + mod) % mod;
}

signed main() {
    // if (!system("fc replace.out replace4.ans")) puts("Yes");
    // else puts("No");
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    scanf("%lld %lld", &n, &q);
    pw[0] = 1ll;
    for (int i = 1; i <= n; i ++) pw[i] = pw[i - 1] * base % mod;
    for (int i = 1; i <= n; i ++){
        scanf("%s%s", s[0] + 1, s[1] + 1);
        len[i] = strlen(s[1] + 1);
        // printf("%lld\n", len[i]);
        for (int j = 1; j <= len[i]; j ++) H0[i] = H0[i] * base + s[0][j] - 'a', H0[i] %= mod;
        for (int j = 1; j <= len[i]; j ++) H1[i] = H1[i] * base + s[1][j] - 'a', H1[i] %= mod;
        // printf("%lld %lld\n", H0[i], H1[i]);
    }
    for (int t = 1; t <= q; t ++){
        ans = 0;
        scanf("%s%s", T[0] + 1, T[1] + 1);
        int Len[2];
        Len[0] = strlen(T[0] + 1);
        Len[1] = strlen(T[1] + 1);
        if (Len[0] != Len[1]){
            puts("0");
            continue;
        }
        int l = 0, r = 0;
        for (int i = 1; i <= Len[0]; i ++){
            Hash0[i] = Hash0[i - 1] * base + T[0][i] - 'a', Hash0[i] %= mod;
            Hash1[i] = Hash1[i - 1] * base + T[1][i] - 'a', Hash1[i] %= mod;
            if (l == 0 && T[0][i] != T[1][i]){
                l = i;
                r = i;
            }
            else if (T[0][i] != T[1][i]) r = i;
        }
        // for (int i = 1; i <= Len[0]; i ++) printf("%c", T[0][i]);
        // puts("");
        // for (int i = 1; i <= Len[0]; i ++) printf("%c", T[1][i]);
        // puts("");
        // printf("%lld %lld\n", l, r);
        // puts("Check");
        for (int i = 1; i <= l; i ++){
            for (int j = 1; j <= n; j ++){
                int en = i + len[j] - 1;
                // printf("len? %lld %lld\n", i, en);
                if (en > Len[0] || en < r) continue;
                // printf("check %lld %lld %lld %lld %lld %lld\n", i, j, check0(i, en), H0[j], check1(i, en), H1[j]);
                if (check0(i, en) == H0[j] && check1(i, en) == H1[j]) ans ++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}