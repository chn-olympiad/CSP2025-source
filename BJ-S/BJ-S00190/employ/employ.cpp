#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;

const int N=505;
int a[N];
char s[N];
int n,m;
bool vis[N];
ll ans=0;
ll jc[N];
int t[N];
void dfs(int i,int cnt){
    //printf("%d %d\n",i,cnt);
    if(cnt==m){
        ans=(ans+jc[n-i+1])%mod;
        return;
    }
    if(i==n+1){
        return;
    }
    for(int j=1;j<=n;j++){
        if(vis[j]) continue;
        vis[j]=true;
        if(a[j]<=i-cnt-1||s[i]=='0'){
            dfs(i+1,cnt);
        }
        else{
            dfs(i+1,cnt+1);
        }
        vis[j]=false;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    bool flag1=true;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0') flag1=false;
    }
    bool flag2=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[a[i]]++;
        if(a[i]==0){
            flag2=false;
        }
    }
    jc[0]=jc[1]=1;
    for(int i=2;i<=n;i++){
        jc[i]=(jc[i-1]*i)%mod;
    }
    if(n==m){
        if(flag1&&flag2){
            printf("%lld",jc[n]);
        }
        else{
            printf("0");
        }
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            t[i]=t[i-1]+t[i];
        }
        int cnt=0;
        ll ans=1;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                ans=(ans*(t[i-1]-cnt))%mod;
                cnt++;
            }
        }
        ans=(ans*jc[n-cnt])%mod;
        printf("%lld",(jc[n]-ans+mod)%mod);
        return 0;
    }
    sort(a+1,a+1+n);
    dfs(1,0);
    printf("%lld",ans);
    return 0;
}
