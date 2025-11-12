#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005],ans,sum,maxx;
bool tot(){
    sum=0;
    maxx=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){sum+=a[i];maxx=a[i];}
    }
    if(sum>maxx*2)return 1;
    else return 0;
}
void dfs(int x){
    if(x==n+1){
        if(tot())ans++;
        return;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],dp[5005][5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n-2;i++){
        if(a[i]+a[i+1]>a[i+2])dp[i][i+2]=1;
    }
    for(int i=4;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j-i+1][j]=dp[j-i+2][j]*2+dp[j-i+1][j-1];

        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
*/
