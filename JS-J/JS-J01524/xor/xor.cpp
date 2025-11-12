#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int n,k,a[MAXN],maxk[MAXN],dp[MAXN];
bool b[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n>=MAXN){
        return 0;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        int ans=0;
        for(int j=i;j<=n;++j){
            ans^=a[j];
            if(ans==k)b[i][j]=1;
        }
    }
    for(int j=1;j<=n;++j){
        maxk[j]=maxk[j-1];
        for(int i=1;i<=j;++i){
            if(b[i][j]){
                maxk[j]=max(maxk[j],i);
            }
        }
    }
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        if(!maxk[i])continue;
        dp[i]=max(dp[i],dp[maxk[i]-1]+1);
    }
    cout<<dp[n];
    return 0;
}
