#include<bits/stdc++.h>
using namespace std;
int T,n[6],a[6][100001][4],dp[6][100001][4],b[6][100001][4][4];
int s;
int ljq(int z,int k,int l){
    int o1,o2,o3,p1,p2,p3,ans,m1=0;
    o1=max(dp[z][k-1][1],dp[z][k-1][2]);
    o2=max(dp[z][k-1][2],dp[z][k-1][3]);
    o3=max(o1,o2);
    for(int i=1;i<=3;i++)
        if(o3==dp[z][k-1][i]){
        p1=i;
        for(int j=1;j<=3;j++){
             if(j!=p1&&dp[z][k-1][j]>=m1){
             m1=dp[z][k-1][j];
             p2=j;
             }
        }
        for(int j=1;j<=3;j++){
            if(j!=p1&&j!=p2)
                p3=j;
        }
    }

    if(b[z][k-1][p1][l]+1>s){
        if(b[z][k-1][p2][l]+1>s){
            b[z][k][l][l]=b[z][k-1][p3][l]+1;
               cout<<"333"<<b[z][k][l][l]<<endl;
            return p3;}
        else{
                b[z][k][l][l]=b[z][k-1][p2][l]+1;
               cout<<"222"<<b[z][k][l][l]<<endl;
            return p2;}
    }
    else{
        b[z][k][l][l]=b[z][k-1][p1][l]+1;

               cout<<"111"<<b[z][k][l][l]<<endl;
        return p1;}
}
int main(){
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++)
            cin>>a[i][j][1]>>a[i][j][2]>>a[i][j][3];
    }
    for(int i=1;i<=T;i++){
        s=n[i]/2;
        dp[i][1][1]=a[i][1][1];
        dp[i][1][2]=a[i][1][2];
        dp[i][1][3]=a[i][1][3];
        b[i][1][1][1]=1;
        b[i][1][2][2]=1;
        b[i][1][3][3]=1;
        for(int j=2;j<=n[i];j++){
            for(int x=1;x<=3;x++){
                int y;
                y=ljq(i,j,x);
                cout<<j<<" "<<x<<" "<<y<<endl;
                dp[i][j][x]=dp[i][j-1][y]+a[i][j][x];
                cout<<dp[i][j][x]<<endl;
            }
        }
        int m1=0;
        for(int j=1;j<=3;j++)
            if(dp[i][n[i]][j]>=m1)
                m1=dp[i][n[i]][j];
        cout<<m1<<endl;
    }
    return 0;
}
