#include <iostream>
#define int long long
using namespace std;
const int mod=998244353,MAXN=5e3+1;
int n,stick[MAXN],ans;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> stick[i];
    for(int i=1;i<=n;i++) // l
        for(int j=i;j<=n;j++){ // r
            int sum=0,maxs=-1e9;
            if(j-i<3) continue;
            for(int k=i;k<=j;k++){
                sum+=stick[k];
                maxs=max(maxs,stick[k]);
            }if(sum>2*maxs) ans=(ans+1)%mod;
        }
    cout << ans;
    return 0;
}