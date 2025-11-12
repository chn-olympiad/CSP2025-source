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
int n, m, a[104], tmp, id, x, y;
inline bool cmp(const int &x, const int &y){
    return x > y;
}
int main(){
    fileio("seat");
    read(n), read(m);
    for (int i=1;i<=n*m;i++) read(a[i]);
    tmp = a[1];
    sort(a+1, a+1+n*m, cmp);
    id = lower_bound(a+1, a+1+n*m, tmp, cmp)-a;
    x = (id-1)/n+1, y = (id-1) % n+1;
    if (x%2==0) y = n - y + 1;
    write(x), pu(32), write(y);
    return 0;
}
