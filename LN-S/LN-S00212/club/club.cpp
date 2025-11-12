#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int R = 210,RR = 100010;
int a[R][5],dp[R][R][R];
bool cmp(int xx,int yy){
    return xx > yy;
}
struct pp{
    int pos,cha;
};
bool ccmp(pp xx,pp yy){
    return xx.cha > yy.cha;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int fw;
    cin>>fw;
    for(int gw = 1;gw <= fw;gw++){
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        bool A=1,B=1;
        for(int i = 1;i <= n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0){
                A=0;
            }if(a[i][3]!=0){
                A=0;
                B=0;
            }
        }
        if(A){
            int k[RR];
            for(int i = 1;i <= n;i++){
                k[i] = a[i][1];
            }
            sort(k+1,k+1+n,cmp);
            int ans = 0;
            for(int i = 1;i <= n/2;i++){
                ans+=k[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(B){
            pp k[RR];
            for(int i = 1;i <= n;i++){
                k[i].pos = i;
                k[i].cha = a[i][2] - a[i][1];
            }
            sort(k+1,k+n+1,ccmp);
            int ans = 0;
            for(int i = 1;i <= n/2;i++){
                ans += a[k[i].pos][2];
            }
            for(int i = n/2 +1;i <= n;i++){
                ans += a[k[i].pos][1];
            }
            cout<<ans<<endl;
            continue;
        }
        int mmax = 0;
        for(int k = 1;k <= n;k++){
            for(int i = k;i >= 0;i--){
                if(i > k)continue;
                for(int j = k-i;j >= 0;j--){
                    if(i+j > k)continue;
                    for(int x = k-i-j;x >= 0;x--){
                        if(i+j+x > k)continue;
                        if(i != 0){
                            dp[i][j][x] = max(dp[i][j][x],dp[i-1][j][x] + a[k][1]);
                        }
                        if(j != 0){
                            dp[i][j][x] = max(dp[i][j][x],dp[i][j-1][x] + a[k][2]);
                        }
                        if(x != 0){
                            dp[i][j][x] = max(dp[i][j][x],dp[i][j][x-1] + a[k][3]);
                        }
                        //if(i + j + x == n){
                        //    mmax = max(mmax,dp[i][j][x]);
                        //}
                    }
                }
            }
        }
        //for(int i = 0;i <= n/2;i++){
        //    for(int j = 0;j <= n/2;j++){
        //        for(int x = 0;x <= n/2;x++){
        //            cout<<dp[i][j][x]<<" ";
        //        }
        //        cout<<" ";
        //    }
        //    cout<<endl;
        //}
        for(int i = 0;i <= n/2;i++){
            for(int j = n/2-i;j <= n/2;j++){
                int k = n-i-j;
                mmax = max(mmax,dp[i][j][k]);
            }
        }
        cout<<mmax<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
