#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long res,cnt;
int k[maxn][4];
int a,b,c;
void dfs(int x) {
    if(x>n) {
        res=max(res,cnt);
        return ;
    }
    if(a<n/2) { cnt+=k[x][1]; ++a; dfs(x+1); cnt-=k[x][1]; --a; }
    if(b<n/2) { cnt+=k[x][2]; ++b; dfs(x+1); cnt-=k[x][2]; --b; }
    if(c<n/2) { cnt+=k[x][3]; ++c; dfs(x+1); cnt-=k[x][3]; --c; }
}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) {
        cnt=res=a=b=c=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d%d%d",&k[i][1],&k[i][2],&k[i][3]);
        }
        dfs(1);
        printf("%lld\n",res);
    }
    return 0;
}
