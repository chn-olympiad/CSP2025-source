#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

inline void read(int &x){
    x=0;bool f=false;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=true;c=getchar();}
    while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    x=f?-x:x;return ;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>10) write(x/10);
    putchar('0'+x%10);
    return ;
}
inline void print(int x){write(x);putchar('\n');}

const int N = 3e6 + 10, mod = 998244353, base = 911;
const int inf = 2e18;

int n, q, m;
int b[N];
string s, t;
map<int, map<int, int> > cnt;
int qpow(int a, int b){
    int res = 1;
    while(b){if(b & 1) res = res * a % mod;b >>= 1;a = a * a % mod;}
    return res;
}

signed main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    read(n);read(q);
    b[0] = 1;
    for(int i = 1; i < N; i++) b[i] = b[i - 1] * base % mod;
    for(int i = 1; i <= n; i++){
        cin >> s>> t;m = s.size();
        int ha1 = 0, ha = 0, ans = 0, ls = -1, rs = -1;
        for(int i = 0; i < m; i++){
            if(s[i] != t[i]){if(ls == -1) ls = i;rs = i;}
        }
        if(ls == -1 && rs == -1) continue;
        for(int i = ls; i <= rs; i++){
            ha = (ha * base % mod + (s[i] - t[i])) % mod;
        }
        int h1 = 0, h2 = 0;
        for(int i = 0; i < m; i++) h1 = (h1 * base % mod + s[i] - 'a') % mod;
        cnt[ha][h1]++;
    }
    while(q--){
        cin >> s>> t;m = s.size();
        int ha1 = 0, ha = 0, ans = 0, ls = -1, rs = -1;
        for(int i = 0; i < m; i++){
            if(s[i] != t[i]){if(ls == -1) ls = i;rs = i;}
        }
        for(int i = ls; i <= rs; i++){
            ha = (ha * base % mod + (s[i] - t[i])) % mod;
        }
        for(int i = 0; i <= ls; i++){
            int ba = 0;
            for(int j = i; j < m; j++){
                ba = (ba * base % mod + s[j] - 'a') % mod;
                if(j >= rs) ans += cnt[ha][ba];
            }
        }
        print(ans);
    }
    return 0;
}