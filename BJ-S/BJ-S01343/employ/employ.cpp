#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],dp[510][510];
bool s[510];
string ss;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>ss;
    for(int i=0;i<n;i++){
        s[i+1]=ss[i]-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+n);
    int nxt=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i]==0)nxt++;
        bool f=0;
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(i==n)dp[i][j]=max(dp[i-1][j]-1,0);
            if(s[i]==1){


                for(int k=n;c[k]>nxt && k>=1;k--){
                    f=1;
                    if(i==n)dp[i][j]+=max(dp[i-1][j-1]-1,0);
                    else dp[i][j]+=dp[i-1][j-1];
                }

            }
            dp[i][j]%=998244353;

        }
        if(f)nxt=0;
    }
    cout<<dp[n][m];
    return 0;
}
