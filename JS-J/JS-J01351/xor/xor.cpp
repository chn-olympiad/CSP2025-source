#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
int n,k;
int a[114514],dp[1145][1145];
int dfs(int l,int r){
    if(dp[l][r]!=0)return dp[l][r];
    for(int k=l;k<=r-1;k++){
        dp[l][r]=max(dp[l][r],dfs(l,k)+dfs(k+1,r));
    }
    return dp[l][r];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int xxor=a[i];
        if(xxor==k){
            dp[i][i]=1;
            continue;
        }
        for(int j=i+1;j<=n;j++){
            xxor=xxor^a[j];
            if(xxor==k){
                dp[i][j]=1;
                break;
            }
        }
    }
    cout<<dfs(1,n)<<endl;
    return 0;
}
