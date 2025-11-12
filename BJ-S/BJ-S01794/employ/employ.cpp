#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int mod=998244353;
char c[N];
int jie[N];
int dp[N][N],cnt[N];
int C[N][N];
int xi[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        cnt[t]++;
    }
    for(int i=n;i>=0;i--)cnt[i]+=cnt[i+1];
    jie[0]=1;
    for(int i=1;i<=n;i++)jie[i]=1ll*jie[i-1]*i%mod;
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    int ans=0;
   // xi[5]=1,xi[6]=-5,xi[7]=15,xi[8]=-35;
    for(int k=m;k<=n;k++){
        dp[n+1][0]=1;
        for(int i=n;i>=1;i--){
            for(int j=0;j<=k;j++){
                int no=(i-1)-(k-j);
                if(c[i]=='0'||j==0)dp[i][j]=dp[i+1][j];
                else dp[i][j]=(dp[i+1][j]+1ll*dp[i+1][j-1]*(cnt[no+1]-j+1)%mod);
            }
        }
       /* cout<<dp[1][k]<<" ";
        int ci=0;
        for(int j=m;j<k;j++){
            if((j-m)&1)ci+=C[k][j];
            else ci-=C[k][j];
        }*/
        if(((k-m)&1)==0)ans+=1ll*dp[1][k]*jie[n-k]%mod;
        else ans-=1ll*dp[1][k]*jie[n-k]%mod;
        ans%=mod;
    }
    cout<<(ans+mod)%mod;
    return 0;
}
