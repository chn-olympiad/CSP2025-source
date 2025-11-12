#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=25;
const int M=263000;
const ll mod=998244353;
ll n,m,f[M][19],s[N],a[N];
char c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>c+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+(c[i]=='0');
    }
    if(n<=18){
        ll now=(1<<n)-1;
        f[0][0]=1;
        for(int i=0;i<=now;i++){
            ll cnt=0;
            for(int j=1;j<=n;j++){
                if(i&(1<<(j-1))){
                    cnt++;
                }
            }
            for(int j=0;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(!(i&(1<<(k-1))))continue;
                    ll Nah=cnt-j;
                    if(c[cnt]=='0'){
                        f[i][j]=(f[i][j]+f[i-(1<<(k-1))][j])%mod;
                    }
                    else{
                        if(Nah-1>=a[k]){
                            f[i][j]=(f[i][j]+f[i-(1<<(k-1))][j])%mod;                  
                        }
                        else if(Nah<a[k])f[i][j]=(f[i][j]+f[i-(1<<(k-1))][j-1])%mod;
                    }
                }
            }
        }
        ll ans=0;
        for(int i=m;i<=n;i++){
            ans=(ans+f[now][i])%mod;
        }
        cout<<ans<<"\n";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(c[i]=='0'){
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]=='1'){
            cout<<0;
            return 0;
        }
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%mod;
    }
    cout<<ans<<"\n";
    return 0;
}