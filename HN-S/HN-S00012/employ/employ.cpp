#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
const int mod=998244853;
int n,m,a[maxn],c[maxn],fac[maxn],p[maxn];
int pls(int a,int b){ return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b){ return a>=b?a-b:a-b+mod; }
int mul(int a,int b){ return 1ll*a*b%mod; }
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m; fac[0]=1;
    for(int i=1;i<=n;i++){
        fac[i]=mul(fac[i-1],i);
        p[i]=i;
    }
    for(int i=1;i<=n;i++){
        char ch; cin>>ch;
        a[i]=ch-'0';
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
        
    }
    int ans=0;
    do{
        int g=0;
        for(int i=1;i<=n;i++){
            if(!a[i]||c[p[i]]<=g) g++;
        }
        // cerr<<g<<'\n';
        ans=pls(ans,n-g>=m);
    }while(next_permutation(p+1,p+n+1));
    cout<<ans;
    return 0;
}