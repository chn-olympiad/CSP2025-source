#include<bits/stdc++.h>
using namespace std;
long long n;long long dp[10005],a[10005],b[10005],cnt=0,flag=0;
void dfs(long long target,long long pos,long long now){
    if(now>target){
        long long sum=1;
        for(long long i=1;i<=pos;i++){
            long long fenz=1,fenm=1;
            for(long long j=pos;j>pos-i;j--){
                fenz=(fenz*j)%998244353;
            }
            for(long long j=1;j<=i;j++){
                fenm=(fenm*j)%998244353;
            }
            sum+=(fenz/fenm)%998244353;
        }
        if((flag!=0)&&sum==1)flag=1,sum=0;
        cnt=(cnt+sum)%998244353;
        return ;
    }
    for(long long i=pos-1;i>=1;i--){
        dfs(target,i,now+a[pos]);
    }
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){cin>>a[i];}
    int teshu=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1)teshu=1;
    }
    if(teshu==0){
        long long cor=0;
        for(long long i=3;i<=n;i++){
            long long fenz=1,fenm=1;
            for(int j=n;j>n-i;j--){
                fenz=(fenz*j)%998244353;
            }
            for(int j=1;j<=i;j++){
                fenm=(fenm*j)%998244353;
            }
            cor+=(fenz/fenm)%998244353;
    }
    cout<<cor;
    return 0;
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){b[i]=b[i-1]+a[i];}
    dp[1]=0;dp[2]=0;
    if(a[1]+a[2]>a[3])dp[3]=1;
    else dp[3]=0;
    for(long long i=4;i<=n;i++){
        if(b[i-1]<=a[i])dp[i]=0;
        else{
            dfs(a[i],i-1,0);
            dp[i]=cnt;
            cnt=0;
            flag=0;
        }
    }
    int ans=0;
    for(long long i=1;i<=n;i++)ans=(ans+dp[i])%998244353;
    cout<<ans;
    return 0;
}

