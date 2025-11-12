#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const long long mod=998244353;
long long n,a[5010],ans,maxna,dp[2][50010][2];bool fl[5010];
bool cmp(long long x,long long y){return x>y;}
void dfs(long long now){
    if(now==n+1){
        long long sum=0,maxn=0;
        for(int i=1;i<=n;i++){
            sum+=(fl[i]*a[i]);
            maxn=max(maxn,fl[i]*a[i]);
        }
        if(sum>2*maxn){
            //for(int i=1;i<=n;i++)cout<<fl[i]<<' ';
            //cout<<'\n';
            ++ans;
        }
        return;
    }
    fl[now]=false;
    dfs(now+1);
    fl[now]=true;
    dfs(now+1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],maxna=max(maxna,a[i]);
    sort(a+1,a+n+1);
    if(n<=20){
        dfs(1);
        cout<<ans<<'\n';
        return 0;
    }
    if(maxna==1){
        ans=1;
        for(int i=1;i<=n;i++)ans*=2ll,ans%=mod;;
        ans=(ans+mod-1ll-n-n*(n-1)/2)%mod;
        cout<<ans;
        return 0;
    }
    ans=0;
    if(n<=500){
         dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            int th=i%2,la=(i+1)%2;
            for(int j=0;j<=50000;j++)dp[th][j][0]=dp[th][j][1]=0;
            for(int j=0;j<=50000;j++){
                if(j+a[i]<=50000)dp[th][j+a[i]][1]+=dp[la][j][0],dp[th][j+a[i]][0]+=dp[la][j][0];
                dp[th][j][0]+=dp[la][j][0];
                dp[th][j][0]%=mod,dp[th][j+a[i]][1]%=mod,dp[th][j+a[i]][0]%=mod;
            }
            if(i<3)continue;
            for(int j=a[i]*2+1;j<=50000;j++){
                ans+=dp[th][j][1];
                ans%=mod;
            }
        }
        cout<<ans;
        return 0;
    }

    dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            int th=i%2,la=(i+1)%2;
            for(int j=0;j<=10005;j++)dp[th][j][0]=dp[th][j][1]=0;
            for(int j=0;j<=10005;j++){
                if(j+a[i]<=10005)dp[th][j+a[i]][1]+=dp[la][j][0],dp[th][j+a[i]][0]+=dp[la][j][0];
                else dp[th][10005][1]+=dp[la][j][0],dp[th][10005][0]+=dp[la][j][0];
                dp[th][j][0]+=dp[la][j][0];
                dp[th][j][0]%=mod,dp[th][j+a[i]][1]%=mod,dp[th][j+a[i]][0]%=mod;
            }
            /*for(int j=1;j<=20;j++)cout<<dp[i][j][0]<<' ';
            cout<<'\n';
            for(int j=1;j<=20;j++)cout<<dp[i][j][1]<<' ';
            cout<<'\n';*/
            if(i<3)continue;
            for(int j=a[i]*2+1;j<=10005;j++){
                ans+=dp[th][j][1];
                ans%=mod;
            }
        }
        cout<<ans;
        return 0;



}
