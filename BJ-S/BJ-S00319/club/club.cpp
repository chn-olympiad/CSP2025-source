#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,maxx=-2e9;
vector<vector<ll> > a;
//dp[i][j][k][l]表示当只考虑前i个第一个部门为j人第二个部门为k人时第三个部门为l人时(i<=n,j/k/l<=n/2)
//则dp[i][j][k][l]=max(dp[i-1][j-1][k][l]+a[i][1],dp[i-1][j][k-1][l]+a[i][2],dp[i-1][j][k][l-1]+a[i][3],dp[i-1][j][k][l])
//默认dp[i][0][0][0]=0;
vector<vector<vector<ll> > > dp[2];
bool cmp(vector<ll> a,vector<ll> b){
    return a[0]>b[0];
}
void solve(ll T){
    while(T--){
        cin>>n,a=vector<vector<ll> >(n,vector<ll>(3,0));
        ll flag=3;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][1]!=0)
                flag=min(flag,2LL);
            if(a[i][2]!=0)
                flag=min(flag,1LL);
        }
        if(flag==3){
            ll sum=0;
            sort(a.begin(),a.end(),cmp);
            for(int i=0;i<n/2;i++)
                sum+=a[i][0];
            cout<<sum<<"\n";
            continue;
        }
        if(flag==2){
            dp[0]=vector<vector<vector<ll> > >(n/2+1,vector<vector<ll> >(n/2+1,vector<ll>(1,0))),dp[1]=dp[0];
            for(int i=0;i<n;i++){
                for(int j=0;j<=n/2;j++){
                    for(int k=0;k<=n/2;k++){
                        ll l=0;
                        dp[i%2][j][k][l]=dp[(i+1)%2][j][k][l];
                        if(j!=0)
                            dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i+1)%2][j-1][k][l]+a[i][0]);
                        if(k!=0)
                            dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i+1)%2][j][k-1][l]+a[i][1]);
                        if(i==n-1)
                            maxx=max(dp[i%2][j][k][l],maxx);
                    }
                }          
            }
            cout<<maxx<<"\n",maxx=-2e9;
            continue; 
        }
        dp[0]=vector<vector<vector<ll> > >(n/2+1,vector<vector<ll> >(n/2+1,vector<ll>(n/2+1,0))),dp[1]=dp[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<=n/2;j++){
                for(int k=0;k<=n/2;k++){
                    for(int l=0;l<=n/2;l++){
                        dp[i%2][j][k][l]=dp[(i+1)%2][j][k][l];
                        if(j!=0)
                            dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i+1)%2][j-1][k][l]+a[i][0]);
                        if(k!=0)
                            dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i+1)%2][j][k-1][l]+a[i][1]);
                        if(l!=0)
                            dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i+1)%2][j][k][l-1]+a[i][2]);
                        if(i==n-1)
                            maxx=max(dp[i%2][j][k][l],maxx);
                    }
                }         
            }           
        }
        cout<<maxx<<"\n",maxx=-2e9;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll T;
    cin>>T;
    solve(T);
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
优化:
    对于已知i,j,k的情况下
    其他人都选l
    则l=min(n/2,max(0,i-j-k))
    (以上会进行滚轮——空间优化)
*/