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
const int MOD=998244353, MAXL=533333; 
int qpow(int base, int power) {
    ll prod=1; 
    while (power) {
        if (power&1) prod*=base, prod%=MOD; 
        base*=base, power>>=1, base%=MOD; 
    }
    return prod; 
}

int n,k, a[MAXL]{-1}, cnt[2]; 
il bool checkA() {
    LP(i, n) if (a[i]!=1) return 0; 
    return 1; 
}
il bool checkB() {
    LP(i, n) if (a[i]>1) return 0; 
    return 1; 
}
il int solveA() {
    if (k==0) return n/2; 
    else {
        // Code there will never run~~ Meow~~
        return n; 
    }
}
il int solveB() {
    vector<int> con; 
    LP(i, n) {
        ++cnt[a[i]&1]; 
        if (k==0&&a[i]==1) {
            if (a[i]!=a[i-1]) con.push_back(1); 
            else ++con.back(); 
        }
    }
    if (k==1) return cnt[1]; 
    int ans=0; 
    for (auto i:con) ans+=i/2; 
    return ans+cnt[0]; 
}
il int solve() {
    if (checkA()) return solveA(); 
    if (checkB()) return solveB(); 
    return 0; 
}
int main() {
#ifndef DBG
    freopen("xor.in", "r", stdin); 
    freopen("xor.out", "w", stdout); 
#endif 
    n=qr(), k=qr(); 
    LP(i, n) a[i]=qr(); 
    cout << solve() << '\n'; 
    return 0; 
}