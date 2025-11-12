#include <bits/stdc++.h>
#if __linux__
#define ge getchar_unlocked
#define pu putchar_unlocked
#else
#define ge getchar
#define pu putchar
#endif
using namespace std;
typedef long long ll;
char ch;
template <typename T>
inline void read(T &x){
    x=0;bool sgn = 0;
    while ('0'>ch||ch>'9') ch=ge(), sgn |= ch=='-';
    while ('0'<=ch&&ch<='9') x=x*10+ch-'0', ch=ge();
    if (sgn) x=-x;
}
template <typename T>
inline void write(T x){
    if (x<0) pu('-'), x=-x;
    static int sta[110], top = 0;
    do sta[top++] = x%10, x/=10;while (x);
    while (top) pu(sta[--top]+'0');
}
#define fileio(i) freopen(i".in", "r", stdin), freopen(i".out", "w", stdout)
const int N = 5004;
const ll mod = 998244353;
int n, a[N];
ll f[N], g[N], p2[N], ans;
int main(){
    fileio("polygon");
    read(n);
    p2[0] = 1;
    for (int i=1;i<=n;i++) read(a[i]), p2[i] = p2[i-1] * 2 % mod;
    sort(a+1, a+1+n);
    f[0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=a[n];j>=a[i];--j){
            f[j] = (f[j] + f[j-a[i]])%mod;
        }
        for (int j=0;j<=a[i+1];++j) g[i+1] = (g[i+1] + f[j])%mod;
    }
    for (int i=3;i<=n;i++){
        ans = (ans + p2[i-1] - g[i])%mod;
    }
    write((ans+mod)%mod);
    return 0;
}
