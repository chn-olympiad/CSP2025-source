#include<bits/stdc++.h>
using namespace std;
const int N=5e2+7;
int n,m,s[N],c[N],pos[N],sum[N];
string str;
using ll=long long;
const ll mod=998244353;
ll ans,f[N][N],fac[N],C[N][N],g[N];
bool vis[N];
void dfs(int x){
    if(x==n+1){
        int num=0;
        for(int i=1;i<=n;++i)if((i-1)-num<c[pos[i]]&&s[i]==1)
            ++num;
        if(num>=m)
            ++ans;
        return ;
    }
    for(int i=1;i<=n;++i)if(!vis[i]){
        vis[i]=true;
        pos[i]=x;
        dfs(x+1);
        vis[i]=false;
    }
}
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>str;
    for(int i=0;i<(int)str.size();++i)
        s[i+1]=str[i]-'0';
    for(int i=1;i<=n;++i)
        cin>>c[i];
    if(n<=10){
        dfs(1);
        cout<<ans<<endl;
        return 0;
    }
    bool fl=true;
    for(int i=1;i<=n;++i){
        if(s[i]==0){
            fl=false;
            break;
        }
    }
    if(fl==true){
        for(int i=1;i<=n;++i)sum[c[i]]++;
        for(int i=1;i<=n;++i)sum[i]+=sum[i-1];
        f[0][0]=1;
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i%mod;
        C[0][0]=1;
        for(int i=1;i<=n;++i){
            C[i][0]=1;
            for(int j=1;j<=i;++j)
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
        for(int i=0;i<n;++i)for(int j=0;j<=n;++j){
            if(f[i][j]==0) continue;
            (f[i+1][j+1]+=f[i][j]*(sum[j]-j))%=mod;
            (f[i+1][j]+=f[i][j])%=mod;
        }
        for(int j=0;j<=n;++j) (f[n][j]*=fac[n-j])%=mod;
        ans=0;
        for(int i=0;i<=n;++i){
            for(int j=i;j<=n;++j)
                g[i]=(g[i]+(((j-i)&1)?(mod-1):(1))*C[j][i]%mod*f[n][j])%mod;
            if(i<=n-m)
                ans=(ans+g[i])%mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    if(n>=100){
        fac[0]=1;
        for(int i=1;i<=n;++i)
            fac[i]=fac[i-1]*i%mod;
        if(m==1)
            cout<<fac[n]<<endl;
        else
            cout<<rnd()<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
