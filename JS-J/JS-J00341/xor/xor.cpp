#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,s[N],sn[N],len,dp[N],dpn[N],f[N],g[N],ans,num[N];//QZH
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>num[i];
        g[i]=INT_MAX;
        if(i==1) s[i]=num[i];
        else s[i]=s[i-1]^num[i];
    }
    for(int i=n;i>=1;i--){
        if(i==n) sn[i]=num[i];
        else sn[i]=sn[i+1]^num[i];
    }


    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((s[j]^s[i])==k){
                f[j]=max(f[j],i+1);

            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i+1;j<=n+1;j++){
            if((sn[i]^sn[j])==k){
                g[i]=min(g[i],j-1);

            }
        }
    }
    if(f[1]!=0) dp[1]=1;
    for(int i=1;i<=n;i++){
        if(f[i]!=0){
            for(int j=1;j<=i-1;j++){
                 dp[i]=max(dp[j],dp[f[i]-1]+1);
            }
        }
    }
    //cout<<dp[1]<<endl;
    for(int i=n;i>=1;i--){
       if(g[i]!=INT_MAX){
            for(int j=i+1;j<=n+1;j++){
                 dpn[i]=max(dpn[j],dpn[g[i]+1]+1);
            }
        }
    }
    //for(int i=1;i<=n;i++){
    //    cout<<dp[i]<<' ';
    //}cout<<endl;
    //for(int i=1;i<=n;i++){
    //    cout<<dpn[i]<<' ';
    //}cout<<endl;
    for(int i=1;i<=n-1;i++){
        ans=max(ans,(dp[i]+dpn[i+1]));
    }//cout<<endl;
    cout<<ans;
    return 0;
}
