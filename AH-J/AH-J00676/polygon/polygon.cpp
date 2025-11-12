#include <bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,a[5005],sp[5005],dp[5005][5005];

int search(int k,int step){
    //if(dp[k][step])return dp[k][step];
    if(step>n||k>n)return 0;
    int num=0;
    sp[step]=a[k];
    if(step>=3){
        int maxn=-1,sum=0;
        for(int i=1;i<=step;i++){
            maxn=max(maxn,sp[i]);
            sum+=sp[i];
        }
        if(sum>maxn*2)num++;
    }

    for(int i=k+1;i<=n;i++){
        num+=search(i,step+1)%mod;
    }
    //dp[k][step]=num;
    return num%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n-2;i++){
        ans+=search(i,1)%mod;
    }
    cout<<ans%mod;
    return 0;
}

