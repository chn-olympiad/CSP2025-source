#include<bits/stdc++.h>
//#define int long long
using namespace std;
int dp[5055][10155];
int a[5555];
int ma=0;
int n;
const int M=998244353;
int po(int y){
   int cnt=1;
   while(y--){
    cnt*=2;
    cnt%=M;
   }
   return cnt;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    sort(a,a+n);
    dp[0][a[0]]=dp[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=(ma*2);j++){
            dp[i][j]+=dp[i-1][j]%M;
            if(j+a[i]<=(ma*2)){
                dp[i][j+a[i]]+=dp[i-1][j];
                dp[i][j+a[i]]%=M;
            }
            dp[i][j]%=M;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=po(i)%M;
        for(int j=1;j<=(2*a[i]);j++){
            //ans+=M;
            ans-=dp[i][j];
            ans%=M;
            if(i!=0) ans+=dp[i-1][j];
            ans%=M;
        }
        //cout<<a[i]<<" "<<ans<<endl;
    }
    ans%=M;
    cout<<ans<<endl;
    return 0;
}
/*
JJJJJJJJJJ   RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
    JJ       RP++
J   JJ       RP++
JJ  JJ       RP++
 JJJJ        RP++
*/
//10:36 AC so AK!! ??
