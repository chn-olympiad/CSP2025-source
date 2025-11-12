#include <bits/stdc++.h>
#define N 22
#define M 500002
#define MOD 998244353
#define ll long long
using namespace std;
int n,m,s[N],c[N];
ll dp[M][N],ans;
string t;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)  s[i]=t[i-1]-'0';
    for(int i=1;i<=n;i++)  cin>>c[i];
    dp[0][0]=1;
    for(int i=0;i<=n;i++){  //day
        for(int j=0;j<(1<<n);j++){  //status
            int cnt=0;
            for(int k=1;k<=n;k++)  if((j>>(k-1))&1)  cnt++;
            if(cnt!=i)  continue;
            for(int k=0;k<=i;k++){  //fail cnt
                for(int l=1;l<=n;l++){  //user
                    if((j>>(l-1))&1)  continue;
                    if(k>=c[l]||s[i+1]==0){
                        dp[(1<<(l-1))|j][k+1]=(dp[(1<<(l-1))|j][k+1]+dp[j][k])%MOD;
                        // cout<<dp[(1<<(l-1))|j][k]<<": "<<((1<<(l-1))|j)<<", "<<k<<"\n";
                    }else{
                        dp[(1<<(l-1))|j][k]=(dp[(1<<(l-1))|j][k]+dp[j][k])%MOD;
                        // cout<<dp[(1<<(l-1))|j][k+1]<<": "<<((1<<(l-1))|j)<<", "<<k+1<<"\n";
                    }
                    // cout<<j<<"\n";
                }
            }
        }
    }
    for(int i=0;i<=n-m;i++)  (ans+=dp[(1<<n)-1][i])%=MOD;
    cout<<ans<<"\n";
    return 0;
}