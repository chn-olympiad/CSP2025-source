#include<bits/stdc++.h>
#define int long long
#define lowbit(u) ((u)&-(u))
using namespace std;

const int N=500+10,T=1<<19,N2=20,MOD=998244353;
int lg[T],_2[T],dp[N2][T],cnt[T];
char str[N];int c[N],n,m;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>str+1;for(int i=1;i<=n;i++)cin>>c[i];
    if(n<=18){
        _2[1]=lg[1]=1;for(int i=2;i<=n;i++)lg[_2[i]=_2[i-1]<<1]=i;
        dp[0][0]=1;
        for(int i=1;i<(1<<n);i++){
            cnt[i]=cnt[i^lowbit(i)]+1;
            for(int j=0;j<cnt[i];j++){
                int k=i,u;while(k){
                    u=lg[lowbit(k)];
                    (dp[j+(c[u]<=j||str[cnt[i]]=='0')][i]+=dp[j][i^lowbit(k)])%=MOD;
                    k^=lowbit(k);
                }
            }
        }
        int ans=0;
        for(int i=m;i<=n;i++){
            (ans+=dp[n-i][(1<<n)-1])%=MOD;
        }cout<<ans<<'\n';;
        return 0;
    }
    int cnt=0;for(int i=1;i<=n;i++)if(str[i]=='1')cnt++;
    if(cnt>=n){
        int ans=1;for(int i=2;i<=n;i++)ans=ans*i%MOD;cout<<ans;
        return 0;
    }cout<<0<<'\n';
    return 0;
}
