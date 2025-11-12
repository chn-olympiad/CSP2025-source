#include<bits/stdc++.h>
using namespace std;
#define il inline
const int mod=998244353;
il void add(int &a,int b){
    a=(a+b>=mod?a+b-mod:a+b);
}
const int N=510;
int n,m;
char s[N];
int b[N];
int f[N][N],fac[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        int c;
        cin>>c;
        b[c]++;
    }
    for(int i=1;i<=n;i++)b[i]+=b[i-1];
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            for(int j=i-1;j>=0;j--){
                for(int k=i-1;k>=0;k--){
                    f[j+1][k]=f[j][k];
                    f[j][k]=0;
                }
            }
        }
        else for(int j=i-1;j>=0;j--){
            for(int k=min(b[j],i)-1;k>=0;k--){
                add(f[j+1][k+1],1ll*f[j][k]*(b[j]-k)%mod);
                add(f[j][k+1],mod-1ll*f[j][k]*(b[j]-k)%mod);
            }
        }
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
    int ans=0;
    for(int j=0;j<=n-m;j++)
        for(int k=0;k<=n;k++)
            add(ans,1ll*f[j][k]*fac[n-k]%mod);
    cout<<ans;
    return 0;
}
