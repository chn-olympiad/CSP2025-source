#include<bits/stdc++.h>
using namespace std;
const int N=105;
int dp[N][N][N],ans;
char s[N];
int n,m,c[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
        for(int i=1;i<=n;i++){
            dp[1][i][0]=1;
        }
    for(int i=2;i<=n;i++){
        for(int cur=1;cur<=n;cur++){
            for(int j=0;j<i;j++){
                for(int pre=1;pre<=n;pre++){
                    if(pre==cur) continue;
                    if(i-j-1>=c[cur]){
                        dp[i][cur][j]+=dp[i-1][pre][j];
                    }
                    else if(s[i]=='0'){
                        dp[i][cur][j]+=dp[i-1][pre][j];
                    }
                    else{
                        if(j>=1) dp[i][cur][j]+=dp[i-1][pre][j-1];
                    }
                }
                if(i==n&&j>=m) ans+=dp[i][cur][j];
            }
        }
    }
    cout<<ans;
    return 0;
}
