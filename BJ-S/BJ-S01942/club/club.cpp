#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
unsigned int n,t,dp[1503][1503][203],sum;//dp i c1 c2
struct stu{
    int v1,v2,v3;
}a[1503];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        sum=0;
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[j].v1>>a[j].v2>>a[j].v3;
        }
        for(unsigned int j=1;j<=n;j++){
            for(unsigned int c1=0;c1<=min(n/2,j);c1++){
                for(unsigned int c2=0;c2<=min(n/2,j-c1);c2++){
                    if(c1==0&&c2==0){
                        dp[j][c1][c2]=dp[j-1][c1][c2]+a[j].v3;
                    }
                    else if(c1==0){
                        dp[j][c1][c2]=max(dp[j-1][c1][c2-1]+a[j].v2,dp[j-1][c1][c2]+a[j].v3);
                    }
                    else if(c2==0){
                        dp[j][c1][c2]=max(dp[j-1][c1-1][c2]+a[j].v1,dp[j-1][c1][c2]+a[j].v3);
                    }
                    else{
                        dp[j][c1][c2]=max(dp[j-1][c1-1][c2]+a[j].v1,max(dp[j-1][c1][c2-1]+a[j].v2,dp[j-1][c1][c2]+a[j].v3));
                    }
                    if(j==n){
                        sum=max(sum,dp[j][c1][c2]);
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
