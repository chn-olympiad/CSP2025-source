#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

const int N = 505;
const ll mod = 998244353;
int n,m,p[N],c[N],vis[N];
char s[N];ll ans=0;

void dfs(int now){
    if(now>n){
        int ok=0,killed=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'||killed>=c[p[i]])killed++;
            else{ok++;if(ok>=m){ans++;ans%=mod;break;}}
        }
        return;
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        vis[i]=1,p[now]=i;dfs(now+1);
        vis[i]=0,p[now]=0;
    }
}

int main(){
    freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
    n=read(),m=read();scanf("%s",s+1);for(int i=1;i<=n;i++)c[i]=read();
    if(m==n){
        bool flag=1;
        for(int i=1;i<=n;i++)if(s[i]=='0'||c[i]==0){flag=0;break;}
        if(!flag)return puts("0"),0;ans=1;for(int i=1;i<=n;i++)ans=ans*i%mod;
        printf("%lld\n",ans);return 0;
    }
    if(m==1){
        int id=0;for(int i=1;i<=n;i++)if(s[i]=='1'){id=i;break;}
        if(id==0)return puts("0"),0;ll cnt=0;ans=1;for(int i=1;i<n;i++)ans=ans*i%mod;
        for(int i=1;i<=n;i++)if(c[i]>id-1)cnt++;ans=ans*cnt%mod;printf("%lld\n",ans);return 0;
    }
    dfs(1);printf("%lld\n",ans);
    return 0;
}