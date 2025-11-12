#include<bits/stdc++.h>
using namespace std;
/*long long n,a[5005],ans,b[5005],c[5005],dp[5005][5005];
long long dfs(int x,int maxx){
    if(dp[x][maxx]==-1){
        if(x==1){
            if(a[1]<=maxx)dp[x][maxx]=0;
            else if(maxx<0)dp[x][maxx]=2;
            else dp[x][maxx]=1;
        }
        else if(maxx>=b[x]){dp[x][maxx]=0;}
        else if(maxx<0){
            maxx=-1;
            long long y=pow(2,x);
            y%=998244353;
            dp[x][maxx]=y;
        }
        else dp[x][maxx]=(dfs(x-1,maxx-a[x])+dfs(x-1,maxx))%998244353;
    }
    return dp[x][maxx];
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    for(int i=-500;i<5000;i++){
        for(int j=0;j<5000;j++){
            dp[i][j]=-1;
        }

    }

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
    sort(a+1,a+n+1);
    //for(int i=3;i<=n;i++){
    //    ans+=dfs(i-1,a[i]);
    //    ans%=998244353;
    //}
    cout<<dfs(4,5)<<ans;
    return 0;
}*/
long long n,a[5005],ans,b[5005],c[5005];
long long dfs(int x,int maxx){

    if(x==1){
        if(a[1]<=maxx)return 0;
        else if(maxx<0)return 2;
        else return 1;
    }
    if(maxx>=b[x]){return 0;}
    if(maxx<0){
        long long y=pow(2,x);
        y%=998244353;
        return y;
    }

    return (dfs(x-1,maxx-a[x])+dfs(x-1,maxx))%998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++){
        ans+=dfs(i-1,a[i]);
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}

/*long long n,a[5005],ans;
void dfs(int x,int maxx,long long sum,int las){
    if(x==0){
        if(maxx*2<sum) ans++;
    }
    else{
        for(int i=las+1;i<n;i++){
            dfs(x-1,a[i],sum+a[i],i);
        }
    }
}
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=3;i<=n;i++){
        dfs(i,0,0,-1);
    }
    cout<<ans;
    return 0;
}*/
