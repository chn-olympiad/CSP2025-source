#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5],id[N];
int ans=0;
int vis[N];
void dfs(int dep,int p1,int p2,int p3){
    if(dep>n){
        int res=0;
        for(int i=1;i<=n;i++) res+=a[i][vis[i]];
        ans=max(ans,res);
        return;
    }
    if(p1<n/2) vis[dep]=1,dfs(dep+1,p1+1,p2,p3);
    if(p2<n/2) vis[dep]=2,dfs(dep+1,p1,p2+1,p3);
    if(p3<n/2) vis[dep]=3,dfs(dep+1,p1,p2,p3+1);
}
inline bool cmp1(const int &x,const int &y){
    return a[x][1]>a[y][1];
}
inline bool cmp2(const int &x,const int &y){
    if(a[x][1]+a[y][2]!=a[x][2]+a[y][1]) return a[x][1]+a[y][2]>a[x][2]+a[y][1];
    return a[x][1]>a[y][1];
}
void solve(){
    memset(id,0,sizeof(id));
    memset(vis,0,sizeof(vis));
    ans=0;
    scanf("%d",&n);
    bool is_2=1,is_3=1;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        id[i]=i;
        if(a[i][2]!=0) is_2=0;
        if(a[i][3]!=0) is_3=0;
    }
    if(is_2&&is_3){
        sort(id+1,id+1+n,cmp1);
        for(int i=1;i<=n/2;i++) ans+=a[id[i]][1];
        printf("%d\n",ans);
        return;
    }
    if(is_3){
        sort(id+1,id+1+n,cmp2);
        for(int i=1;i<=n;i++){
            if(i<=n/2) ans+=a[id[i]][1];
            else ans+=a[id[i]][2];
        }
        printf("%d\n",ans);
        return;
    }
    dfs(1,0,0,0);
    printf("%d\n",ans);
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
