#include <bits/stdc++.h>
using namespace std;
int n,t;
struct node{
    int x[3],sum;
    double bias;
}a[100001];
bool cmp(node x,node y){
    if(abs(x.bias-y.bias)<=1e-5)
        return x.sum>y.sum;
    return x.bias>y.bias;
}
struct state{
    int mx,n[3];
}dp[100001][3];
void init(int i){
    dp[i][0].mx=dp[i][0].n[0]=dp[i][0].n[2]=dp[i][0].n[3]=0;
    dp[i][1].mx=dp[i][1].n[1]=dp[i][1].n[2]=dp[i][1].n[3]=0;
    dp[i][2].mx=dp[i][2].n[1]=dp[i][2].n[2]=dp[i][2].n[3]=0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        init(0);
        for(int i=1;i<=n;i++){
            cin>>a[i].x[0]>>a[i].x[1]>>a[i].x[2];
            int mx=max(a[i].x[0],max(a[i].x[1],a[i].x[2]));
            a[i].sum=a[i].x[1]+a[i].x[2]+a[i].x[0];
            a[i].bias=(double)mx/a[i].sum;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            init(i);
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(dp[i-1][k].n[j]<n/2&&dp[i][j].mx<=dp[i-1][k].mx+a[i].x[j])
                    dp[i][j].mx=dp[i-1][k].mx+a[i].x[j],dp[i][j].n[0]=dp[i-1][k].n[0],
                    dp[i][j].n[1]=dp[i-1][k].n[1],dp[i][j].n[2]=dp[i-1][k].n[2],dp[i][j].n[j]++;
                }
            }
        }cout<<max(dp[n][0].mx,max(dp[n][1].mx,dp[n][2].mx))<<endl;
    }
}
