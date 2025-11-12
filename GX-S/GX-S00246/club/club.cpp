#include<bits/stdc++.h>
using namespace std;
struct abc{
    int a;
    int i;
};
bool cmp(abc a,abc b){
    return a.a>b.a;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        abc a[n+1][4];
        memset(a,0,sizeof(a));
     //   int b[n+1];
  //     memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j].a;
                a[i][j].i=j;
            }
            sort(a[i]+1,a[i]+1+3,cmp);
       //     b[i]=max(a[i][1],max(a[i][2],a[i][3]));
        }
        int f=0;
    //    int d[4]={0,0,0,0};
        int n2=n/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
         //       if(d[a[i][j].i]<n2){
       //             cout<<f<<" ";
                    f=f+a[i][j].a;
         //           d[a[i][j].i]++;
                    break;
       //         }
            }

        }

     //   int f[n+1];

    //    memset(f,0,sizeof(f));
    /*    for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(b[i]==a[i][j]&&d[j]<n2){
                    f[i]=max(f[i],f[i-1]+a[i][j]);
                    d[j]++;
                }
            }
        }*/
        cout<<f<<"\n";
   /*     int dp[n+1][4][n2+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){

                for(int k=1;k<=n2;k++){

                    dp[i][j][k]=dp[i-1][j][k-1]+a[i][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cout<<dp[i][j][n2]<<" ";
            }
            cout<<"\n";
        }*/
   }
    return 0;
}
