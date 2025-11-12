/********************
 * @GavinCQTD
 * 2025/11/1 CSP-S
 * D. employ
 * 1000 ms / 512 MB
********************/

#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

namespace Gavin{
    constexpr int MOD=998244353;
    
    int n,m,c[505],ans=0;
    string s;
    bitset<505> tg;
    
    void dfs(int u,int drp){
        if(u-1-drp+n-u+1<m){
            return;
        }
        if(u==n+1){
            ans++;
            ans %= MOD;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!tg[i]){
                tg[i] = true;
                bool vv=(s[u]=='0'||drp>=c[i]);
                dfs(u+1,drp+(vv?1:0));
                tg[i] = false;
            }
        }
    }
    
    int main(){
        cin >> n >> m >> s;
        s = ' '+s;
        for(int i=1;i<=n;i++){
            cin >> c[i];
        }
        
        dfs(1,0);
        
        cout << ans << "\n";

        return 0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    return Gavin::main();
}

