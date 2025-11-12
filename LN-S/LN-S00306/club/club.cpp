#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,bz,a[100005],b[100005],c[100005];
bool cmp(int p,int q){
    return p>q;
}
void dfs(int x,int y,int z,int sum){
    if(x+y+z==n){
        ans=max(ans,sum);
        return;
    }
    int now=x+y+z+1;
    if(x+1<=n/2) dfs(x+1,y,z,sum+a[now]);
    if(y+1<=n/2) dfs(x,y+1,z,sum+b[now]);
    if(z+1<=n/2) dfs(x,y,z+1,sum+c[now]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
            if((b[i]!=0)||c[i]!=0) bz=1;
        }
        if(bz==0){
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=a[i];
            printf("%lld\n",ans);
            continue;
        }
        dfs(0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
