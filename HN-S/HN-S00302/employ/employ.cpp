#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m,c[N],inv[N],fac[N],tot,lp,ans,f[N],fl;
string s;
int add(int a,int b){
    return (a+b)%mod;
}
int mul(int a,int b){
    return (a*b)%mod;
}
int ksm(int a,int b){
    int c=1;
    while(b){
        if(b&1)
            c=mul(c,a);
        a=mul(a,a);
        b>>=1;
    }
    return c;
}
int choose(int a,int b){
    if(a<b) return 0;
    return mul(fac[a],mul(inv[b],inv[a-b]));
}
void dfs(int x,int res,int no){
    if(res==m){
        ans=add(ans,fac[n-x+1]);
        return;
    }
    if(x==n+1) return;
    for(int i=1;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            if(c[i]>x-res-1&&s[no]=='1')
                dfs(x+1,res+1,no+1);
            else dfs(x+1,res,no+1);
            f[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){   
        cin>>c[i];
        if(c[i]==0) fl++;
    }
    fac[0]=1,inv[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=mul(fac[i-1],i);
    inv[n]=ksm(fac[n],mod-2);
    for(int i=n-1;i>0;i--)
        inv[i]=mul(inv[i+1],i+1);
    if(m==n){
        if(fl==n&&lp==0) cout<<fac[n];
        else cout<<0;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}