#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,pa[503],cnt[503];
const int mod=998244353;
string s;
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>pa[i];
        if(cnt[i-1]>=pa[i])cnt[i]=cnt[i-1]+1;
    }
    n=n-cnt[n];
        int t=1;
        for(int j=1;j<=n;j++){
            t=t*j%mod;
        }
    cout<<t;
    return 0;
}
