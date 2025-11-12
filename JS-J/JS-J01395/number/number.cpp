// Xue_Zhoujun_RhF6 AK IOI!!!!!!!!!!!!!!!!!!!!!!!!!!!
// If you CE, check "; " 
// QwQ AwA OvO QaQ TaT
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
const int MOD=998244353, MAXL=114514; 
int qpow(int base, int power) {
    ll prod=1; 
    while (power) {
        if (power&1) prod*=base, prod%=MOD; 
        base*=base, power>>=1, base%=MOD; 
    }
    return prod; 
}

string s; 
int main() {
#ifndef DBG
    freopen("number.in", "r", stdin); 
    freopen("number.out", "w", stdout); 
#endif 
    cin >> s; 
    string t=""; 
    for (auto c:s) if (isdigit(c)) t.push_back(c); 
    sort(t.begin(), t.end(), greater<char>());
    cout << t << '\n';  
    return 0; 
}