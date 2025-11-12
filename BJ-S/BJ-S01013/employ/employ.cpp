#include<bits/stdc++.h>
using namespace std;

const int N=5e2+5,mod=998244353;
int n,m,s[N],c[N],fac[N];
int ans;
bool vis[N];

void init(){
    fac[0]=fac[1]=1;
    for(int i=2;i<N;i++) fac[i]=fac[i-1]*i%mod;
    return;
}
void dfs(int k,int in){
    if(in==m){
        ans=(ans+fac[n-k+1])%mod;
        return;
    }
    if(k>n) return;
    if(in+n-k+1<m) return;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            if(!s[k]) dfs(k+1,in);
            else {
                if(k-in-1<c[i]) dfs(k+1,in+1);
                else dfs(k+1,in);
            }
            vis[i]=false;
        }
    }
}

int main(){
    //freopen("employ.in","w",stdout);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        s[i]=ch-'0';
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    if(m==n) cout<<fac[n];
    else{
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
/*
Ren5Jie4Di4Ling5%
*/
