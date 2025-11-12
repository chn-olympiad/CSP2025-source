#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
int n,a[N],b[N][N]={0},cnt=0,dp[N][2]={0};
int main(){
    freopen("polygon.in","r",stdin);//please open it
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    memset(b,0,sizeof b);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int num=a[i],maxn=a[i];
        for(int j=i+1;j<=n;j++){
            num+=a[j];
            maxn=max(maxn,a[j]);
            if(j-i+1>=3&&num>=maxn*2){
                cnt++;
            }
        }
    }
    cout<<cnt;
   return 0;
}

