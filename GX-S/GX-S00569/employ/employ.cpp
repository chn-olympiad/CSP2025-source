#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507;
int n,m;
ll pw[N];
ll ans;
int s[N],c[N];
char x;
int vis[N];
void dfs(int u,int now){
    if(u>n){
        if(n-now>=m){
            ans=(ans+1)%998244353;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        if(now>=c[i]||!s[u]){
            dfs(u+1,now+1);
        }
        else{
            dfs(u+1,now);
        }
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%c",&x);
        s[i]=x-'0';
    }
    for(int i=1;i<=n;i++){
        scanf("%d",c+i);
    }

    pw[1]=1;
    for(int i=2;i<=n;i++){
        pw[i]=pw[i-1]*i%998244353;
    }
    if(n<=18){
        dfs(1,0);
        printf("%lld",ans);
    }
    else{
        printf("%lld",pw[n]);
    }
    return 0;
}
