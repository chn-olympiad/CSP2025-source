#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,a[31][4],dp[31][16][16][16],a3,res,M;
void solve(){
    memset(dp,0,sizeof(dp));
    res=0;
    cin>>n;
    M=n>>1;
    for(int i=1;i<=n;i++){
    //    cin>>s[i].a>>s[i].b>>s[i].c;
        cin>>a[i][1]>>a[i][2]>>a[i][3];
    }
    //sort(s+1,s+1+n,cmp);
    //for(int i=1;i<=n;i++){
    //    a[i][1]=s[i].a;
    //    a[i][2]=s[i].b;
    //    a[i][3]=s[i].c;
    //}
    for(int i=1;i<=n;i++){
        for(int a1=0;a1<=n/2&&a1<=i;a1++){
            for(int a2=0;a2<=n/2&&a2+a1<=i;a2++){
                a3=i-a1-a2;
                if(a3>M){
                    continue;
                }
                if(a1!=0){
                    dp[i][a1][a2][a3]=max(dp[i][a1][a2][a3],dp[i-1][a1-1][a2][a3]+a[i][1]);
                }
                if(a2!=0){
                    dp[i][a1][a2][a3]=max(dp[i][a1][a2][a3],dp[i-1][a1][a2-1][a3]+a[i][2]);
                }
                if(a3!=0){
                    dp[i][a1][a2][a3]=max(dp[i][a1][a2][a3],dp[i-1][a1][a2][a3-1]+a[i][3]);
                }
                if(n==i){
                    res=max(res,dp[i][a1][a2][a3]);
                }
            }
        }
    }
    cout<<res<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
