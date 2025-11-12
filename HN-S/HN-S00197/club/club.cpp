#include<bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
const int N1=210,N=1e5+10;
int t,n,a[N][5],dp[N1/2][N1/2][N1/2],b[N];
pair<int,int>c[N];
bool A,B;
void solve1(){
    memset(dp,0,sizeof(dp));
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=min(i,n/2);j>=0;j--){
            for(int k=min(i,n/2);k>=0;k--){
                if(B){
                    if(j&&dp[j-1][k][0]+a[i][1]>dp[j][k][0]){
                        dp[j][k][0]=dp[j-1][k][0]+a[i][1];
                    }
                    if(k&&dp[j][k-1][0]+a[i][2]>dp[j][k][0]){
                        dp[j][k][0]=dp[j][k-1][0]+a[i][2];
                    }
                    res=max(res,dp[j][k][0]);
                    continue;
                }
                for(int p=min(i,n/2);p>=0;p--){
                    if(j&&dp[j-1][k][p]+a[i][1]>dp[j][k][p]){
                        dp[j][k][p]=dp[j-1][k][p]+a[i][1];
                    }
                    if(k&&dp[j][k-1][p]+a[i][2]>dp[j][k][p]){
                        dp[j][k][p]=dp[j][k-1][p]+a[i][2];
                    }
                    if(p&&dp[j][k][p-1]+a[i][3]>dp[j][k][p]){
                        dp[j][k][p]=dp[j][k][p-1]+a[i][3];
                    }
                    res=max(res,dp[j][k][p]);
                }
            }
        }
    }
    cout<<res<<endl;
}
void solve2(){
    for(int i=1;i<=n;i++){
        b[i]=a[i][1];
    }
    sort(b+1,b+n+1,[=](int a,int b){return a>b;});
    int res=0;
    for(int i=1;i<=n/2;i++){
        res+=b[i];
    }
    cout<<res<<endl;
}
void solve3(){
    int res=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i][2]-a[i][1];
        res+=a[i][1];
    }
    sort(b+1,b+n+1,[=](int a,int b){return a>b;});
    for(int i=1;i<=n/2;i++){
        res+=b[i];
    }
    cout<<res<<endl;
}
// void solve4(){
//     int res=0;
//     for(int i=1;i<=n;i++){
//         b[i]=max(a[i][2]-a[i][1],a[i][3]-a[i][1]);
//         res+=a[i][1];
//     }
//     sort(b+1,b+n+1,[=](int a,int b){return a>b;});
//     for(int i=1;i<=n/2;i++){
//         res+=b[i];
//     }
//     cout<<res<<endl;
// }
void solve4(){
    int res=0;
    for(int i=1;i<=n;i++){
        c[i]={i,a[i][2]-a[i][1]};
        res+=a[i][1];
    }
    sort(c+1,c+n+1,[=](pair<int,int>a,pair<int,int>b){return a.sec>b.sec;});
    for(int i=1;i<=n/2;i++){
        res+=c[i].sec;
        b[i]=a[c[i].fir][3]-a[c[i].fir][2];
    }
    for(int i=n/2+1;i<=n;i++){
        b[i]=a[c[i].fir][3]-a[c[i].fir][1];
    }
    sort(b+1,b+n+1,[=](int a,int b){return a>b;});
    for(int i=1;i<=n/2&&b[i]>0;i++){
        res+=b[i];
    }
    cout<<res<<endl;
}
void solve(){
    cin>>n;
    A=B=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
            if(j>=2&&a[i][j])A=0;
            if(j==3&&a[i][j])B=0;
        }
    }
    if(A)solve2();
    else if(n<=200)solve1();
    else if(B)solve3();
    else solve4();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)solve();
    return 0;
}