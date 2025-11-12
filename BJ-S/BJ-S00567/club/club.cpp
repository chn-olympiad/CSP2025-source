#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[500005];
int n,dp[205][205][205],ans,T;
bool cmp(node a,node b){
    return a.a>b.a;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,-63,sizeof dp);
        dp[0][0][0]=0;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;        
        if(n<=200){
            for(int i=1;i<=n;i++){
                for(int j=0;j<=min(n/2,i);j++){
                    for(int k=0;k<=min(n/2,i-j);k++){
                        if(i-j-k>n/2)continue;
                        dp[i][j][k]=max({dp[i-1][j][k]+a[i].c,j==0?0:dp[i-1][j-1][k]+a[i].a,k==0?0:dp[i-1][j][k-1]+a[i].b});
                        if(i==n)ans=max(ans,dp[i][j][k]);
                    }
                }
                
            }
            cout<<ans<<endl; 
        }else{
            sort(a+1,a+1+n);
            int sum=0;
            for(int i=1;i<=n/2;i++)sum+=a[i].a;
            cout<<sum<<endl;
        }
    }

    return 0;
}