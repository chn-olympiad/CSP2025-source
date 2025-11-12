#include"bits/stdc++.h"
using namespace std;
int un(int au,int yk){
    int bu=0;
    int tn=0;
    if(au==0&&yk==0){
        return 1;
    }
    while(yk){
        bu+=(!(au%2))*pow(2,tn);
        au/=2;
        yk/=2;
        tn++;
    }

    return bu;
}
int xorm(int a,int b){
    return (a|b)&(un(a,max(a,b))|un(b,max(a,b)));
}
int b[500005];
int n,k,ac;
int weight(int l,int r){
    return xorm(b[r],b[l-1]);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int dp[n][n];
    b[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&ac);
        b[i]=xorm(b[i-1],ac);
    }
    for(int l=0;l<n;l++){
        for(int j=1;j+l<=n;j++){
            dp[j][j+l]=0;
            if(weight(j,j+l)==k){
                dp[j][j+l]=1;
            }
            for(int z=j;z<j+l;z++){
                dp[j][j+l]=max(dp[j][j+l],dp[j][z]+dp[z+1][j+l]);
            }
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
