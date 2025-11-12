#include<bits/stdc++.h>
using namespace std;
int dp[210][110][110],n,a[100100],b[100010],c[100010];bool flB=true;
struct num{int a,b;}cl[100010];
bool cmp(num x,num y){
    return x.a-x.b>y.a-y.b;
}
void solve(){
    cin>>n;int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
        if(c[i])flB=false;
    }
    if(flB){
        for(int i=1;i<=n;i++)cl[i].a=a[i],cl[i].b=b[i];
        sort(cl+1,cl+n+1,cmp);
        for(int i=1;i<=n/2;i++)ans+=cl[i].a;
        for(int i=n/2+1;i<=n;i++)ans+=cl[i].b;
        cout<<ans<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i,n/2);j++){
            for(int k=0;k<=min(i,n/2);k++){
                if(i-j-k<0)break;
                if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i]);
                if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+b[i]);
                if(i-k-j<=n/2&&i>k+j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+c[i]);
                ans=max({ans,dp[i][j][k]});
            }
        }
    }
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[i][j][k]=0;
    cout<<ans<<'\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
