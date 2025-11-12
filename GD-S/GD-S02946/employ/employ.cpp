#include<bits/stdc++.h>
using namespace std;
char s[501];
int dp[(1<<18)+5][20];//???
int p[501];
int main()
{
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        cin>>p[i];
    dp[0][0]=1;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<=__builtin_popcount(i);j++)
            for(int x=0;x<n;x++)
                if((i>>x)&1)continue;
                else /*clog<<i<<' '<<j<<' '<<x<<' '<<(p[x]<=j)<<' '<<(s[__builtin_popcount(i)])<<'\n',*/dp[i|(1<<x)][j+((p[x]<=j)||(s[__builtin_popcount(i)]=='0'))]+=dp[i][j];
    // for(int x=0;x<(1<<n);x++){for(int i=0;i<=n;i++)clog<<dp[x][i]<<' ';clog<<'\n';}
    int ans=0;
    for(int i=0;i<=(n-m);i++)
        ans+=dp[(1<<n)-1][i];
    cout<<ans<<'\n';
    return 0;
}