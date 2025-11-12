#include<bits/stdc++.h>
using namespace std;
#define N 505
#define int long long
char ch[N];
int n,m,a[N];
const int mod=998244353;
namespace baoli{
    int ans=0,d[N];   
    void solve(){
        iota(d,d+n+1,0);
        while(1){
            int sum=0;
            for(int i=1;i<=n;i++)
                if(ch[i]=='0'||sum>=a[d[i]])  sum++;
            ans=(ans+(sum<=n-m))%mod;
            if(!next_permutation(d+1,d+n+1))  break;
        }
        cout<<ans<<"\n";
    }
}
namespace mequal1{
    void solve(){
        vector<int> one;int zero=0,fac=1,ans=1;
        for(int i=1;i<=n;i++)
            if(ch[i]=='0')  zero++;
            else  one.push_back(i);
        sort(a+1,a+n+1,[](int x,int y){return x>y;});
        for(int i=1;i<=n;i++)  fac=fac*i%mod;
        for(int i=1;i<=n;i++){
            int tmp=upper_bound(one.begin(),one.end(),a[i])-one.begin();
            int could=zero+one.size()-tmp;
            if(could<i){ans=0;break;}
            else  ans=ans*(could-i+1)%mod;
        }
        cout<<(fac-ans+mod)%mod<<"\n";
    }
}
namespace mequaln{
    void solve(){
        for(int i=1;i<=n;i++){
            if(ch[i]=='1')  continue;
            return cout<<0<<"\n",void();
        }
        sort(a+1,a+n+1);int ans=1;
        for(int i=1;i<=n;i++){
            a[i]=min(a[i],n);
            if(a[i]<i){ans=0;break;}
            else  ans=ans*(a[i]-i+1)%mod;
        }
        cout<<ans<<"\n";
    }
}
namespace SpecialA{
    int C[N][N],dp[N][N],fac[N];
    void solve(){
        dp[0][0]=fac[0]=1,sort(a+1,a+n+1);
        int ans=0;
        for(int i=0;i<N;i++)  C[i][0]=1;
        for(int i=1;i<N;i++)  fac[i]=fac[i-1]*i%mod;
        for(int i=1;i<N;i++)
            for(int j=1;j<=i;j++)
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1]*(a[i]-j+1)%mod;
                dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
            }
        }
        for(int i=m,op=1;i<=n;i++,op=mod-op){
            ans=(ans+dp[n][i]*fac[n-m]%mod*C[i][m]%mod*op)%mod;
        }
        cout<<ans<<"\n";
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)  cin>>ch[i];
    for(int i=1;i<=n;i++)  cin>>a[i];
    // return SpecialA::solve(),0;
    if(n<=10)  return baoli::solve(),0;
    if(m==1)  return mequal1::solve(),0;
    if(m==n)  return mequaln::solve(),0;
    return baoli::solve(),0;
}