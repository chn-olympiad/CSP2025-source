#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500+5,mod=998244353;
int n,m,h[maxn],c[maxn];
ll f[(1<<18)+5][18+1];
void Main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%1d",&h[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m==n){
        ll res=1,xs=1;
        for(int i=1;i<=n;i++){
            res=res*i%mod;
            xs=min(xs,c[i]*h[i]);
        }
        cout<<res*xs<<'\n';
    }
    else{
        f[0][0]=1;
        for(int i=0;i<(1<<n)-1;i++){
            int cnt=__builtin_popcount(i);
            for(int j=0;j<=cnt;j++){
                for(int k=0;k<n;k++){
                    if(!(i>>k&1)){
                        int gu=(h[cnt+1]==0||c[k+1]<=j);
                        (f[i|(1<<k)][j+gu]+=f[i][j])%=mod;
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<=n-m;j++){
            (ans+=f[(1<<n)-1][j])%=mod;
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    Main();
}