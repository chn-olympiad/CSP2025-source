#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;

int n,m,a[510]; string s;

namespace subtask1{
    int c[510],ans;
    void dfs(int k,int t,int sum){
        if(k>n){ if(t>=m)ans=(ans+sum)%mod; return; }
        for(int i=0;i<=n;++i)if(c[i]){
            --c[i];
            dfs(k+1,t+(s[k]=='1'&&(k-1-t<i)),1ll*sum*(c[i]+1)%mod);
            ++c[i];
        }
    }
    inline void Main(){
        for(int i=1;i<=n;++i)++c[a[i]];
        dfs(1,0,1),printf("%d",ans);
    }
};

namespace subtask2{
    int c[510],dp[510][1010];
    inline void Main(){
        for(int i=1;i<=n;++i)++c[a[i]];
        if(c[n]){ puts("0"); return; }
        int ans=1;
        for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
        dp[1][c[0]]=1;
        for(int i=1;i<n;++i){
            for(int j=1;j<=n;++j)dp[i+1][j+c[i]-1]=(dp[i+1][j+c[i]-1]+1ll*dp[i][j]*j)%mod;
            if(s[i]=='0'){
                //puts("I love you");
                for(int j=1;j<=n;++j){
                    //printf("%d ",dp[i+1][j+c[i]]);
                    dp[i+1][j+c[i]]=(dp[i+1][j+c[i]]+1ll*dp[i][j]*(n-(i-1)-j))%mod;
                    //printf("%d\n",dp[i+1][j+c[i]]);
                }
            }
        }
        ans=(ans-dp[n][1]+mod)%mod;
        if(s[n]=='0')ans=(ans-dp[n][0]+mod)%mod;
        printf("%d",ans);
    }
};

namespace subtask3{
    inline void Main(){
        for(int i=1;i<=n;++i)if(s[i]=='0'||!a[i]){
            puts("0"); return;
        }
        int ans=1;
        for(int i=1;i<=n;++i)ans=1ll*ans*i%mod;
        printf("%d",ans);
    }
};

namespace subtask4{
    inline void Main(){
        
    }
};

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m),cin>>s,s=" "+s;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    if(n<=18){ subtask1::Main(); return 0; }
    if(m==1){ subtask2::Main(); return 0; }
    if(m==n){ subtask3::Main(); return 0; }
    //subtask4::Main();
    subtask1::Main();
}