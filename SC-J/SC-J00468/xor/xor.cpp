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
const int N = 5e5+4;
int n, k, a[N], plc[1<<20|7], cnt, ans=1, lst;
struct seg{
    int l, r;
    bool operator<(const seg &other){
        return r < other.r;
    }
}b[N];
int main(){
    fileio("xor");
    read(n), read(k);
    for (int i=1;i<=n;i++){
        read(a[i]);
        a[i] ^= a[i-1];
    }
    for (int i=0;i<=n;i++){
        if (plc[a[i]]!=0) b[++cnt] = {plc[a[i]], i};
        plc[a[i]^k] = i+1;
    }
    sort(b+1, b+1+cnt);
    lst = b[1].r;
    for (int i=2;i<=cnt;++i){
        if (b[i].l>lst) ++ans, lst = b[i].r;
    }
    write(ans);
    return 0;
}
