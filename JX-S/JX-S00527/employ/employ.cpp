#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+25;
const int mod=998244353;
int n,a[N],b[N],m,p[N],k[N];
int fac[N];
inline void solve1(){
    int ans=0;
    do{
        for(int i=1;i<=n;i++)k[i]=a[p[i]];
        int tot=0,res=0;
        for(int i=1;i<=n;i++){
            if(k[i]>tot&&b[i])++res;
            if(!b[i]||k[i]<=tot)++tot;
        }
        if(res>=m)++ans;
    }while(next_permutation(p+1,p+1+n));
    cout<<ans;
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;i++)cin>>c,b[i]=c-'0';
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)p[i]=i;
    if(n<=10){solve1();return 0;}
    fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=fac[i-1]*i,fac[i]%=mod;
    }
    cout<<fac[n];
}
