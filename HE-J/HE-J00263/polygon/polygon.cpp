//gan jue neng AK!!!!!
#include<bits/stdc++.h>
using namespace std;
int n;
//const int MAXN=6000,MAXK=6000;
const int MAXN=6000,MAXK=6000;
int R[MAXN];
bool cmp(int a,int b){
    return a>b;
}
long long ans=0;
const int p=998244353;
int dp[MAXN][MAXK];//dp[i][j]=>   n of in [1,i],equal j [],if j==5001,upper;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>R[i];
    }
    sort(R+1,R+n+1);
    memset(dp,0,MAXN*MAXK);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<MAXK;j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=p;
            dp[i][min(j+R[i],MAXK-1)]+=dp[i-1][j];
            dp[i][min(j+R[i],MAXK-1)]%=p;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=R[i]+1;j<MAXK;j++)
        {
            ans+=dp[i-1][j];
            ans%=p;
        }
    }
    cout<<ans;
    return 0;
}
