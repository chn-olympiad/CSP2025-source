#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int a[5006];
int f[5005][10020];
int p[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    p[0]=1;
    f[0][0]=1;
    for(int i=1;i<=n;i++)p[i]=(p[i-1]*2)%mod;
    for(int i=1;i<=n;i++){
        for(int j=10005;j>=0;j--){
            f[i][j]=f[i-1][j];
            if(j-a[i]>=0)f[i][j]=(f[i][j]+f[i-1][j-a[i]])%mod;

        }
    }
  /*  for(int i=1;i<=n;i++){
        for(int j=0;j<=50;j++)cout<<f[i][j]<<" ";
        cout<<'\n';
    }*/
    int ans=0;
    for(int i=3;i<=n;i++){
        int k=0;
        for(int j=0;j<=a[i];j++)k=(k+f[i-1][j])%mod;
        ans=(ans+(p[i-1]-k))%mod;
   //     cout<<ans<<" ";
    }
  //  cout<<'\n';
    cout<<(ans+mod)%mod;
    return 0;
}
