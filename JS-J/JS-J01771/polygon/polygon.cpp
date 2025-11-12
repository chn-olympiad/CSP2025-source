#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long f[5005][5005];
long long mod=998244353;
int n;
long long cnt;
void dfs(long long sum,int w){
    for(int i=w+1;i<=n;i++){
        if(sum>a[i]){
            cnt=(cnt+1)%mod;

        }
        dfs(sum+a[i],i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=3){
        if(n!=3)cout<<0;
        else if(a[1]+a[2]>a[3])cout<<1;
        else cout<<0;
        return 0;
    }
    if(a[n]==1){
        f[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                f[i][j]=(f[i-1][j]%mod+f[i-1][j-1]%mod)%mod;
            }
        }
        long long ans=0;
        for(int i=3;i<=n;i++){
            for(int j=i;j<=n;j++){
                ans=(ans%mod+f[j][i]%mod)%mod;
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++)dfs(a[i],i);
    cout<<cnt%mod;
    return 0;
}
