#include<bits/stdc++.h>
#define i64 long long 
using namespace std;

const int N=5e4+10,maxn=4e6+10;
const i64 P=998244353;

int n;
i64 ans=0;
int a[N];
i64 fac[N];
bool vis[N],vised[maxn];

int check(){
    int sum=0,mx=0,now=0;
    for(int i=1;i<=n;i++){
        now|=vis[i]; now<<=1;
    }
    // cout<<now<<"<-now"<<endl;
    if(vised[now]) return 0;
    vised[now]=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]) continue;
        mx=max(mx,a[i]); sum+=a[i];
    }
    if(sum>mx*2) return 1;
    else return 0;
}

void dfs(int x,int tot){
    if(x>n+1) return ;
    if(tot>=3){
        ans+=check();
        // /**/for(int i=1;i<=n;i++) 
        //         if(vis[i]) cout<<i<<":";
        //     cout<<endl;
        //     cout<<check()<<"----"<<ans<<endl;
    }
    vis[x]=true; dfs(x+1,tot+1);
    vis[x]=false; dfs(x+1,tot);
    return ;
}

i64 qpow(i64 x,i64 y){
    i64 tmp=1;
    while(y){
        if(y&1) tmp=(tmp*x)%P;
        x=(x*x)%P; y>>=1;
    }
    return tmp%P;
}

i64 C(int x,int y){
    return fac[x]*qpow(fac[y],P-2)%P*qpow(fac[x-y],P-2)%P;
}

void subtask1(){
    memset(vised,0,sizeof vised);
    memset(vis,0,sizeof vis);
    dfs(1,0);
    cout<<ans%P<<'\n';
    return ;
}

void subtask2(){
    fac[1]=1; fac[0]=1; 
    for(int i=2;i<=n;i++) fac[i]=fac[i-1]*i%P;  
    // /**/ for(int i=1;i<=n;i++) cout<<fac[i]<<":";
        // cout<<endl;
    // cout<<C(3,3)<<" "<<qpow(fac[3],P-2)<<'\n';
    for(int i=3;i<=n;i++) ans=(ans+C(n,i))%P;
    cout<<ans%P<<'\n';
    return ;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int mxnum=0;
    for(int i=1;i<=n;i++) cin>>a[i],mxnum=max(mxnum,a[i]);
    if(n<=20){
        subtask1();
        return 0;
    }
    else if(mxnum==1){
        subtask2();
        return 0;
    }
    return 0;
}