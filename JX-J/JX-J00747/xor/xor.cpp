#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n;
ll a[N],cnt=0,num=0,k,dp[N][2]={0};
int main(){
    freopen("xor.in","r",stdin);//please open it
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
//    for(int i=1;i<=n;i++){
//        num^=a[i];
 //       if(num==k){
 //           num=0;
 //           cnt++;
 //       }
 //   }
 //   cout<<cnt;
    //dp[1][0]=0,dp[1][2]=a[1],dp[1][1]=a[1];
    for(int i=1;i<=n;i++){
        dp[i][0]=a[i];
        dp[i][1]=dp[i-1][1]^a[i];
//        cout<<"i="<<i<<"    ";
 //       cout<<"dp[i][0]="<<dp[i][0]<<" dp[i][1]="<<dp[i][1]<<'\n';
        if(dp[i][0]==k){
            dp[i][0]=0;
            dp[i][1]=0;
            cnt++;
        }else if(dp[i][1]==k){
            dp[i][1]=0;
            cnt++;
        }
    }
  /*
   int j=1;
   for(int i=1;i<=n-j+1;i++){
        ll num=a[i];
        if(num==k){
            cnt++;
            continue;
        }
        for(j=i+1;j<=n;j++){
            num^=a[j];
            if(num==k){
                cnt++;
                break;
            }
        }
   }
   */
   cout<<cnt;
   return 0;
}
