// Xue_Zhoujun_RhF6 AK IOI!!!!!!!!!!!!!!!!!!!!!!!!!!!
// If you CE, check "; " 
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define LP(i, n) for (int i=1; i<=n; ++i)
#define FR(i, n) for (int i=0; i<n;  ++i)
#define LOP(i, d, n) for (int i=d; i<=n; ++i)
#define FOR(i, d, n) for (int i=d; i<n;  ++i)
#define il inline
#define gc getchar
#define pc putchar
#define qw qwrite
#define qr qread
// #define DBG
using namespace std; 
using ll=long long; 
using vi=vector<int>; 
using vll=vector<ll>; 
int qread() {
    int sum=0; 
    char c, e=1; 
    while (!isdigit(c=getchar())) if (c=='-') e=-1; else if (c==EOF) return 0; 
    while (isdigit(c)) sum=(sum<<3)+(sum<<1)+(c^48), c=gc(); 
    return e*sum; 
}
void qwrite(int x) {
    if (x<0) pc('-'), x=-x; 
    if (x>9) qwrite(x/10); 
    pc(x%10+'0'); 
}
const int MOD=998244353, MAXL=114; 
int qpow(int base, int power) {
    ll prod=1; 
    while (power) {
        if (power&1) prod*=base, prod%=MOD; 
        base*=base, power>>=1, base%=MOD; 
    }
    return prod; 
}

int n, m, a[MAXL]; 
struct Seat {
    int scr, idx; 
} seat[MAXL]; 
int main() {
#ifndef DBG
    freopen("seat.in", "r", stdin); 
    freopen("seat.out", "w", stdout); 
#endif 
    cin >> n >> m; 
    for (int i=1; i<=n*m; ++i) cin >> seat[i].scr, seat[i].idx=i; 
    sort(seat+1, seat+1+n*m, [](Seat& a, Seat& b) { return a.scr>b.scr; }); 
    int idx=0; 
    LP(i, n*m) {
        if (seat[i].idx==1) idx=i;
        // cout << "DBG:" << seat[i].idx << '\n'; 
    } 
    // cout << "idx:" << idx << '\n'; 
    int c=ceil(idx*1.0/n), r=idx%n; 
    // cout << "idx:" << idx << '\n'; 
    if (c&1&&r==0) r=n; 
    if (!(c&1)&&r!=0) r=n-r+1; 
    if (!(c&1)&&r==0) r=1; 
    cout << c << ' ' << r << '\n'; 
    return 0; 
}