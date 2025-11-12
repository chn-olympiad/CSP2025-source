#include<bits/stdc++.h>
using namespace std;
int a[1145];//orirxfhirulbyhiow4u5byoi555555555555555555555;
int n,m;
int dp[1145][1212];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int cnt=a[i];
            for(int k=i+1;k<=j;k++){
                cnt=(cnt^k);
            }
            dp[i][j]=cnt;

        }
    }

    //for(int len=1;len<=n;len++){
      //  ;
        //for(int j=1;j+len-1<=n;j++){
          //  int k=j+len-1;
            //cout<<j<<' '<<k<<"]:"<<dp[j][k]<<endl;
//
  //      }
    //}
    for(int len=1;len<=n;len++){
        int cnt=0;
        for(int j=1;j+len-1<=n;j++){
            int k=j+len-1;
            if(dp[j][k]==m){
                cnt++;
            }

        }
        maxn+=cnt;
    }

    cout<<maxn;
}
