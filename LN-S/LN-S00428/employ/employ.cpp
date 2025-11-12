#include<bits/stdc++.h>
#define N 505
#define mod 998244353
using namespace std;
char s[N];bool vis[N];
int n,m,ans,c[N],p[N];
void dfs(int x){
    if(x==n+1){int bb=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0')bb++;
            else {
                if(bb>=c[p[i]])bb++;
            }
        }if(n-bb>=m)ans=(ans+1)%mod;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;p[x]=i;
            dfs(x+1);
            vis[i]=0;p[x]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d%s",&n,&m,s+1);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    dfs(1);printf("%d",ans);
    return 0;
}
