#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=505,mod=998244353;
int n,m,pres[maxn],c[maxn],ans;
char in[maxn];
bool vis[maxn],nt[maxn];

void dfs(int p,int cnt){
    #ifdef D
    printf("p:%d cnt:%d\n",p,cnt);
    #endif
    if(p>n){
        if(cnt>=m){
            ans++;
            ans%=mod;
        }
        return;
    }

    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        dfs(p+1,cnt+ (c[i]>pres[i] &&!nt[p] ? 1 : 0));
        vis[i]=0;
    }
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    scanf("%d%d%s",&n,&m,in+1);
    for(int i=1;i<=n;i++){
        pres[i]=pres[i-1]-in[i]+'1';
        nt[i]=in[i]=='0';
        scanf("%d",&c[i]);
    }

    #ifdef D
    for(int i=1;i<=n;i++) printf("%d ",pres[i]);
    putchar('\n');
    #endif

    dfs(1,0);
    printf("%d",ans);

    return 0;
}