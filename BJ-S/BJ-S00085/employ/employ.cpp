#include<bits/stdc++.h>
using namespace std;

const int maxn=510;
const int mod=998244353;
int n,m,a[maxn],c[maxn],sum[maxn];
char s[maxn];

long long ans=0;
bool vis[maxn];
void dfs(int k,int p,int q){
    if(k==n+1){
        if(p>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;a[k]=i;
            if(s[k]=='0' || q>=c[i]) dfs(k+1,p,q+1);
            else dfs(k+1,p+1,q);
            vis[i]=0;
        }
    }
}

long long fac(int n){
    long long r=1;
    for(int i=1;i<=n;i++) r*=i,r%=mod;
    return r;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    if(m==n){
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') flag=0;
        }
        for(int i=1;i<=n;i++){
            if(c[i]==0) flag=0;
        }
        if(flag==0) printf("%d\n",0);
        else{
            printf("%d\n",fac(n)%mod);
        }
    }
    else if(m==1){
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1];
            if(s[i]=='0') sum[i]++;
        }
        sort(c+1,c+1+n,greater<int>());
        int lst=0;ans=1;
        for(int i=1;i<=n;i++){
            int cnt=max(n-c[i]-lst,0)+sum[c[i]];
            ans*=cnt,ans%=mod;lst++;
        }
        ans=fac(n)-ans;ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    else{
        dfs(1,0,0);
        printf("%d\n",ans%mod);
    }
    return 0;
}

