#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
template<typename T> inline void chkmax(T& x,T y){ (x < y) && (x = y); }
template<typename T> inline void chkmin(T& x,T y){ (x > y) && (x = y); }
const int mod = 998244353;
inline void add(int& x,int y){ x += y,(x >= mod) && (x -= mod); }
const int N = 505;
int n,m;
bool S[N];
int c[N];
namespace sub1 {
    int dp[262144 + 5][20];
    inline void main(){
        dp[0][0] = 1;
        for(int s = 0;s < (1 << n) - 1;s++){
            int cnt = 0;
            for(int i = 1;i <= n;i++) cnt += s >> i-1 & 1;
            for(int i = 0;i <= cnt;i++){
                int v = dp[s][i];  if(!v) continue;
                for(int j = 1;j <= n;j++){
                    if(s >> j-1 & 1) continue;
                    if(cnt - i >= c[j] || !S[cnt+1]) add(dp[s | 1 << j-1][i],v);
                    else add(dp[s | 1 << j-1][i+1],v);
                }
            //    cerr << s << " " << i << " " << dp[s][i] << "\n";
            }
        }
        int ans = 0;
        for(int i = m;i <= n;i++) add(ans,dp[(1 << n) - 1][i]);
        cout << ans << "\n";
        return ;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    string _; cin >> _;
    int tmp = 0;
    for(int i = 1;i <= n;i++) S[i] = _[i-1] - '0',tmp += S[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    if(tmp < m){ cout << "0\n"; return 0; }
    if(n <= 18){
        sub1::main();
        return 0;
    }
    return 0;
}
/*
g++ employ.cpp -o employ -std=c++14 -O2 -static
time ./employ
*/