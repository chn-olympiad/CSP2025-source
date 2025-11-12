#include<bits/stdc++.h>
using namespace std;
long long t,n,dp[40][40][40][40],ans=-1;
int a[100006],b[100006],c[100006];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));ans=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n>=200){
            sort(a+1,a+n+1);sort(b+1,b+n+1);
            if(b[n]==0){
                ans=0;
                for(int i=n;i>n/2;i--){
                    ans+=a[i];
                }
            cout<<ans<<'\n';
            continue;
            }

        }
        for(long long  i=1;i<=n;i++){
            for(long long  x=0;x<=min(i,n/2);x++){
                for(long long  y=0;y<=min(i-x,n/2);y++){
                    int z=i-x-y;
                    if(z>n/2) continue;
                    if(x>0) dp[i][x][y][z]=max(dp[i][x][y][z],dp[i-1][x-1][y][z]+a[i]);
                    if(y>0) dp[i][x][y][z]=max(dp[i][x][y][z],dp[i-1][x][y-1][z]+b[i]);
                    if(z>0) dp[i][x][y][z]=max(dp[i][x][y][z],dp[i-1][x][y][z-1]+c[i]);
                }
            }
        }
        for(int x=0;x<=n/2;x++){
            for(int y=0;y<=n/2;y++){
                int z=n-x-y;
                if(z>n/2) continue;
                ans=max(ans,dp[n][x][y][n-x-y]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
