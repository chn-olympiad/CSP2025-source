/********************
 * @GavinCQTD
 * 2025/11/1 CSP-S
 * A. club
 * 1000 ms / 512 MB
********************/

#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

namespace Gavin{
    struct Element{
        int a,b,c;
    };
    
    int t,n;
    ll f[2][5005][5005];
    Element el[100005];
    
    int solve(){
        // cerr << "-----------\n";
        
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> el[i].a >> el[i].b >> el[i].c;
        }
        
        int cur=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=min(n/2,i);j++){
                for(int k=0;k<=min(n/2,i-j);k++){
                    if(i-j-k>n/2){
                        continue;
                    }
                    // 选前 i，当前有 j 个 1，k 个 2
//                    cerr << i << " " << j << " " << k << "\n";
                    if(j>=1){
                        f[cur][j][k] = max(f[cur][j][k],f[cur^1][j-1][k]+el[i].a);
//                        cerr << "1: " << f[cur][j][k] << "\n";
                    }
                    if(k>=1){
                        f[cur][j][k] = max(f[cur][j][k],f[cur^1][j][k-1]+el[i].b);
//                        cerr << "2: " << f[cur][j][k] << "\n";
                    }
                    if(i-j-k>=1){
                        f[cur][j][k] = max(f[cur][j][k],f[cur^1][j][k]+el[i].c);
//                        cerr << "3: " << f[cur][j][k] << "\n";
                    }
                }
            }
            cur ^= 1;
        }
        
        ll ans=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++){
                ans = max(ans,f[cur^1][i][j]);
                f[cur][i][j] = f[cur^1][i][j] = 0;
            }
        }
        
        return ans;
    }
    
    int main(){
        cin >> t;

        for(int i=1;i<=t;i++){
            cout << solve() << "\n";
        }


        return 0;
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    return Gavin::main();
}

