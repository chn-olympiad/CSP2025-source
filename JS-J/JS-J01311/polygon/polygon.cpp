#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005],b[5005],c[5005],d[5005],dp[5005];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    //for(int i=0;i<a[1];i++)dp[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i]*2;j>=0;j--){
            if(j-a[i]<0)dp[j]=(dp[j]+dp[0]+1)%998244353;
            else dp[j]=(dp[j]+dp[j-a[i]])%998244353;
        }
        //for(int j=0;j<a[i];j++)dp[j]=(dp[j]+1)%998244353;
        if(i>2)cnt=(cnt+dp[a[i]*2])%998244353;
        //for(int j=0;j<=a[n]*2;j++)cout<<dp[j]<<" ";
        //cout<<endl;
    }
    cout<<cnt;
    return 0;
}
