#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a[3][N];
int dp[35][35][35][35];
int f[2][205][205][205];
void solve(){
    bool A=true,B=true;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i];
        if(a[2][i]!=0) A=false;
        if(a[1][i]!=0) A=false,B=false;
    }
    //5/100: special case of a2=a3=0. O(nlogn)
    if(A){
        sort(a[0]+1,a[0]+n+1);
        for(int i=n;i>n/2;i--) ans+=a[0][i];
        cout<<ans<<endl;
    }
    //45/100: brute force for n=30. O(n^3), space too large.
    else if(n<=30){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int x=0;x<=i&&x<=n/2;x++){
                for(int y=0;y<=i-x&&y<=n/2;y++){
                    if(i-x-y>n/2){continue;}
                    if(x>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x-1][y][i-x-y]+a[0][i]);
                    if(y>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x][y-1][i-x-y]+a[1][i]);
                    if(i-x-y>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x][y][i-x-y-1]+a[2][i]);
                    //cout<<i<<" "<<x<<" "<<y<<" "<<i-x-y<<" "<<dp[i][x][y][i-x-y]<<endl;
                }
            }
        }
        for(int x=0;x<=n/2;x++){
            for(int y=0;y<=n/2;y++){
                if(n-x-y>n/2) continue;
                ans=max(ans,dp[n][x][y][n-x-y]);
            }
        }
        cout<<ans<<endl;
    }
    else if(n<=200){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int x=0;x<=i&&x<=n/2;x++){
                for(int y=0;y<=i-x&&y<=n/2;y++){
                    int z=i-x-y;
                    if(z>n/2) continue;
                    if(x>0) f[1][x][y][z]=max(f[1][x][y][z],f[0][x-1][y][z]+a[0][i]);
                    if(y>0) f[1][x][y][z]=max(f[1][x][y][z],f[0][x][y-1][z]+a[1][i]);
                    if(z>0) f[1][x][y][z]=max(f[1][x][y][z],f[0][x][y][z-1]+a[2][i]);
                }
            }
            for(int x=0;x<=i&&x<=n/2;x++){
                for(int y=0;y<=i-x&&y<=n/2;y++){
                    int z=i-x-y;
                    if(z>n/2) continue;
                    f[0][x][y][z]=f[1][x][y][z];
                    f[1][x][y][z]=0;
                }
            }
        }
        for(int x=0;x<=n/2;x++){
            for(int y=0;y<=n/2;y++){
                if(n-x-y>n/2) continue;
                ans=max(ans,f[0][x][y][n-x-y]);
            }
        }
        cout<<ans<<endl;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--) solve();
    return 0;
}
