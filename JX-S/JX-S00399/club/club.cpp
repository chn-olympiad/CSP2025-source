#include<bits/stdc++.h>
using namespace std;
int t,n;
struct peo{
    int s1;
    int s2;
    int s3;
}a[205];
//struct club{
  //  int p1;
    //int p2;
    //int p3;
//}p[];
int dp[105][105][105];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        int maxn=0;

        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].s1,&a[i].s2,&a[i].s3);
        }
        //for(int i=1;i<=n;i++){
        //    cout<<a[i].s1<<' '<<a[i].s2<<' '<<a[i].s3<<endl;
        //}
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n/2;i++){
            for(int j=1;j<n/2;j++){
                for(int k=1;k<n-i-j;k++){
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k].s1);
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k].s2);
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k].s3);
                    maxn=max(maxn,dp[i][j][k]);
                }
            }
        }

        cout<<maxn<<'\n';
    }
    return 0;
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=n/2;j++){
            for(int k=1;k<=n/2;k++){
                cout<<dp[i][j][k]<<' ';
            }
            cout<<endl;
        }
        cout<<"--------"<<endl;
    }
    for(int i=1;i<=n;i++){
            for(int j=1;j<n/2;j++){
                for(int k=1;k<n/2;k++){
                    int a1=dp[i-1][j-1][k]+a[i].s1;
                    dp[i][j][k]=max(dp[i][j][k],a1);
                    int a2=dp[i-1][j][k-1]+a[i].s2;
                    dp[i][j][k]=max(dp[i][j][k],a2);
                    if((i-j-k)<n/2){

                    }
                }
            }
        }
    int ai,a1,bi,b1;
            if(a[1].s1>a[1].s2){
                ai=1;
                a1=a[1].s1;
            }
            else {
                ai=2;
                a1=a[1].s2;
            }
            if(a[1].s3>a1){
                ai=3;
                a1=a[1].s3;
            }
            if(a[2].s1>a[2].s2){
                bi=1;
                b1=a[2].s1;
            }
            else {
                bi=2;
                b1=a[2].s2;
            }
            if(a[2].s3>a1){
                bi=3;
                b1=a[2].s3;
            }
    if(n==2){

            int a1[3];
            int b1[3];
            for(int i=1;i<=3;i++){
                cin>>a1[i];
            }
            for(int i=1;i<=3;i++){
                cin>>b1[i];
            }
            if(a1[2]==b1[2]){

            }

        }
}
