#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505;
const int mod=998244353;
int n,m;
int s[N];
int sc[N];
ll jc[N];
ll f[N][N][N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        s[i]=c-'0';
    }
    for(int i=1;i<=n;++i){
        int c;
        cin>>c;
        sc[c]++;
    }
    for(int i=n;i>=0;--i){
        sc[i]+=sc[i+1];
    }
    jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%mod;
    for(int i=m;i<=n;++i){
        f[n+1][0][i]=1;
    }
    for(int i=n;i;--i){
        for(int j=0;j<=n-i;++j){
            for(int k=0;k<=n;++k){
                if(f[i+1][j][k]==0)continue;
                const ll lf=f[i+1][j][k];
                f[i][j][k]=(f[i][j][k]+lf)%mod;
                if(s[i]==0)continue;
                if((i-1)-k+1>=0){
                    int lc=sc[(i-1)-k+1];
                    if(lc>j){
                        f[i][j+1][k]=(f[i][j+1][k]-lf*(lc-j)%mod+mod)%mod;
                    }
                }
                if((i-1)-(k-1)+1>=0){
                    int lc=sc[(i-1)-(k-1)+1];
                    if(lc>j){
                        f[i][j+1][k-1]=(f[i][j+1][k-1]+lf*(lc-j))%mod;
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=n;++i){
        ans=(ans+f[1][i][0]*jc[n-i])%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
g++ -o employ employ.cpp -O2 -std=c++14 && time ./employ
*/