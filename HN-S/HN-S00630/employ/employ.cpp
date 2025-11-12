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

const int N = 20, mod = 998244353, base = 911;
const int K = (1 << 18);
const int inf = 2e18;

int n, m, ans;
string t;
int c[N];
int f[N][N][K];

signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    read(n);read(m);
    cin >> t;t = " " + t;
    for(int i = 1; i <= n; i++) read(c[i]);
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k <= i; k++){
                for(int s = 0; s < (1 << n); s++){
                    if(0 == (s & (1 << (j-1)))){
                        if(k >= c[j] || t[i] == '1') f[i][k + 1][s | (1 << (j-1))] = (f[i][k + 1][s | (1 << (j-1))] + f[i - 1][k][s]) % mod;
                        else f[i][k][s | (1 << (j-1))] = (f[i][k][s | (1 << (j-1))] + f[i - 1][k][s]) % mod;
                    }
                }
            }
        }
    }
    for(int i = 0; i <= m; i++) ans = (ans + f[n][i][(1 << n)-1]);
    print(ans);
    return 0;
}