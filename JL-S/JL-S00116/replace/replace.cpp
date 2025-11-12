#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,b[N],c[N],fa[N],stk[N];
int h[N],e[N],p[N],t[N],stk[N];
long long a[N];
inline void add(int a,int,b){
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
inline void dfs(int u,int p){
    fa[u]=p;
    for(int i=h[u];~i;i=ne[i])
        if(e[i]!=p) dfs(e[i],u);
    }
    inline __calc(int x,__l,__r){
        if(c[x]>=0) return (r-l+1)*b[x]+(r-l+1)*(l+r)/2*c[x];
        ___T=(1-b[x])/c[x];
        if(T<l) return r-l+1;
        if(T>r) return (r-l+1)*b[x]+(r-l+1)*(l+r)/2*c[x];
        return (T-l+1)*b[x]+(T-l+1)*(l+T)/2*c[x]+r-T;
    }inline bool check(int r){
        for(int i=1;i<=n;i++){
                if(calc(i,1,r)<a[i]) return false;
        int dl=1,dr=n;
        while(dl<dr){
                int mid=(dl+dr+1)>>1;
        if(calc(i,mid,r)>=a[i]) dl=mid;
        else dr=mid-1;
        }
        p[i]=1;
        t[i]=dl;
        vis[i]=false;
    }
    sort(p+1,p+n+1,[](int A,int B){return t[A]<t[B];});
    for(int i=1,x=0;i<=n;i++){
            int nom=p[i],top=0;
            while(!vis[now]) vis[stk[++top]=now]=true,now=fa[now];
            while(top) if(t[stk[top--]]<++x) return false;
    }
    return true;
}int main(){
    freopen("replace",r,stdin)
    freopen("replace",w,stdout)
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%||d%d%d",&a[i],&b[i],&c[i]);
    for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
            dfs(1,p);
            vis[0]=true;
            int l=n,r=1e9;
            while(l<r){
                    int mid=(l+r)>>1;
                    if(check(mid)) r=mid;
                    else l=mid+1;
            }
            printf("%d",l);
    return 0;
}
