#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1ll*998244353;
int n,m,c[550],p[550],frac[550],ans;
char ac[550];

bool vis[15];
inline void dfs(int x){
    if(x>n){
        int gaveup=0,acc=0;
        for(int i=1;i<=n;++i){
            if(gaveup>=c[p[i]]){
                gaveup++;
                continue;
            }
            if(ac[i]=='1') acc++;
            else gaveup++;
        }
        if(acc>=m){
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=true;
            p[x]=i;
            dfs(x+1);
            vis[i]=false;
        }
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,ac+1);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    if(n<=10){
        dfs(1);
        printf("%d\n",ans);
    }
    else if(m==1){
        frac[0]=1ll;ll dsum=1;
        int cnt,tmp=0;
        for(int i=1;i<=n;++i) frac[i]=frac[i-1]*1ll*i%mod;
        for(int i=1;i<=n;++i){
            if(ac[i]=='1'){
                cnt=0;
                for(int j=1;j<=n;++j){
                    if(c[j]<=i-1) cnt++;
                }cnt-=tmp;
                tmp++;
                dsum=dsum*1ll*cnt%mod;
            }
        }dsum=dsum*frac[n-tmp]%mod;
        printf("%lld\n",(frac[n]-dsum+mod)%mod);
    }
    else if(m==n){
        frac[0]=1ll;ll dsum=1;
        int cnt,tmp=0;bool flag=true;
        for(int i=1;i<=n;++i) frac[i]=frac[i-1]*1ll*i%mod;
        for(int i=1;i<=n;++i) if(c[i]==0||ac[i]=='0') flag=false;
        if(!flag) printf("0\n");
        else printf("%lld\n",frac[n]%mod);
    }
    return 0;
}
