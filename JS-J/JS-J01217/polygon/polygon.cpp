#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
#define ll long long
ll n,a[N],dp[N][2*N];
unsigned short f[N][N];
ll qsm(ll a,ll b){
    if(b==0)return 1ll;
    if(b==1)return a;
    ll t=qsm(a,b/2);
    if(b&1){
        return t*t%mod*a%mod;
    }
    return t*t%mod;
}
int dfs(int u,int v){
    if(dp[u][v])return dp[u][v];
    if(v==0)return dp[u][v]=1;
    if(v<0||u<1)return 0;
    return dp[u][v]=dfs(u-1,v)+dfs(u-1,v-a[u]);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[a[i]][j]++;
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        //dp[i][0]=1;
        for(int j=0;j<=N*2;j++){
            /*dp[i][j]+=dp[i-1][j]%mod;
            if(j>=a[i]){
                dp[i][j]+=(dp[i-1][j-a[i]])%mod;
            }*/
            dfs(i,j);
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }*/
    ll ans=0;
    for(int i=3;i<=n;i++){
        ll sum=0;//bu he fa 1
        for(int j=max(0ll,a[1]+a[2]+a[3]-a[i]);j<=a[i];j++){
            sum+=dp[i-1][j];
            if(f[j][i-1])sum-=f[j][i-1];
            sum%=mod;
        }
        ll tmp=(i-1)*i/2+i;//bu he fa (3+4)
        if(n>3){
            tmp+=(qsm(2,i-1)-(i-1)-1-(i-1)*(i-2)/2);
        }
        ll total=qsm(2,i)-1;
        //cout<<sum<<' '<<tmp<<' '<<total-sum-tmp<<endl;
        ans+=abs(total-sum-tmp);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
/*
    5
1 2 3 4 5
1 1 0 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 0 
1 1 1 2 1 1 1 0 0 0 0 
1 1 1 2 2 2 2 2 1 1 1 
1 1 1 2 2 3 3 3 3 3 3 
    */
//Noooooo!