#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],dp[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0,ans=0;cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]==1)cnt++;
    }
    if(k==0 and cnt==n){
        cout<<n/2<<endl;return 0;
    }
    else if(k==0){
        cnt=0;
        for(int i=1;i<=n;++i){
            if(a[i]==0 or a[i]==a[i-1]){
                cnt++;
            }
        }
        cout<<cnt<<endl;return 0;
    }
    else if(k==1){
        dp[0]=0;
        for(int i=1;i<=n;++i){
            if(a[i]==k){
                dp[i]=max(dp[i],dp[i-1]+1);continue;
            }
            dp[i]=max(dp[i-1],dp[i]);
            int j=i+1,sum=a[i];
            while(j<=n){
                sum^=a[j];
                if(sum==k)break;
                j++;
            }
            if(sum==k)dp[j]=max(dp[j],dp[i]+1);
        }
        cout<<dp[n]<<endl;return 0;
    }
    dp[0]=0;
    for(int i=1;i<=n;++i){
        dp[i]=max(dp[i-1],dp[i]);
        int j=i,sum=a[i];
        while(j<=n){
            sum^=a[j];
            if(sum==k)break;
            j++;
        }
        if(sum==k)dp[j]=max(dp[j],dp[i]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}
