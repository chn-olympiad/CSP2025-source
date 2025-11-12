//T4 [0,20]
#include<bits/stdc++.h>
using namespace std;
const int N=22,SZ=1e6+10,mod=998244353;
int n,m;
int f[SZ][N],sum[N],c[N];
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;s=' '+s;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='0');
    for(int i=1;i<=n;i++) cin>>c[i];
    int U=(1<<n)-1;
    f[0][0]=1;
    for(int i=1;i<=U;i++){
        int ps=__builtin_popcount(i);
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                if(s[ps]=='0'){
                    for(int k=0;k<=n;k++){
                        f[i][k]=(f[i][k]+f[i^(1<<j)][k])%mod;
                    }
                }else{
                    for(int k=0;k<=n;k++){
                        int op=((sum[ps]+k)>=c[j+1]);
                        //cout<<i<<' '<<k<<' '<<op<<endl;
                        f[i][k+op]=(f[i][k+op]+f[i^(1<<j)][k])%mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(n-i-sum[n]>=m) ans=(ans+f[U][i])%mod;
    }cout<<ans<<endl;
    return 0;
}