#include <bits/stdc++.h>
typedef long long ll;
struct op{
    ll maxn,po,cmax,pm,pc;
};
using namespace std;
ll a[100005][5],dp[10005][10005];
vector<op> acd;
ll t;int mi[5]={0,1,0,0},mj[5]={0,0,1,0};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        ll n;
        cin>>n;
        ll maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }for(int ii=1;ii<=n/2;ii++){
            for(int i=ii;i>=0;i--){
                for(int j=ii;j>=0;j--){
                    if(ii*2-i-j>n/2){
                        continue;
                    }
                    for(int jj=1;jj<=3;jj++){
                        for(int jjj=1;jjj<=3;jjj++){
                            if(i-mi[jj]-mi[jjj]<0||j-mj[jjj]-mj[jj]<0){
                                continue;
                            }
                            dp[i][j]=max(dp[i][j],dp[i-mi[jj]-mi[jjj]][j-mj[jjj]-mj[jj]]+a[ii*2-1][jj]+a[ii*2][jjj]);
                            maxn=max(dp[i][j],maxn);
                        }
                    }//cout<<dp[ii][i][j]<<" ";
                }//cout<<endl;
            }
        }cout<<maxn<<endl;
    }
    return 0;
}
