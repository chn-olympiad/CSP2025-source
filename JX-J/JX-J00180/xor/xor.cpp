#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int f2[21];
int xrh[N][N];
int n,k;
int a[N];
int dp[N];
int xorr(int a,int b){
    vector<int> a2,b2;
    for(int i=20;i>=0;i--){
        if(a/f2[i]){a2.push_back(1);a%=f2[i];}
        else a2.push_back(0);
        if(b/f2[i]){b2.push_back(1);b%=f2[i];}
        else b2.push_back(0);
    }
    int ans=0;
    for(int i=0;i<=20;i++){
        if((a2[i]+b2[i])%2==1)ans+=f2[20-i];
    }
    return ans;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    f2[0]=1;
    for(int i=1;i<=20;i++){
        f2[i]=f2[i-1]*2;
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xrh[i][i]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            xrh[i][j]=xorr(xrh[i][j-1],a[j]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j-1],dp[j]);
            if(xrh[i][j]==k){
                dp[j]=max(dp[j-1]+1,dp[j]);
                i=j+1;
            }
        }
    }
    cout<<dp[n];
    fclose(stdout);
    return 0;
}
