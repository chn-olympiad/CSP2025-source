#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct d{
    ll u,v,w;
}g[1100005],gg[1100005],ggg[1100005];
bool cmp(d x,d y){
    return x.w<y.w;
}
ll n,m,k,c[11][10005],cc[15],ans=1e15,f[100005],l,t[10005],cnt;
ll find(ll x){
    if(f[x]==x){
        return x;
    }
    return f[x]=find(f[x]);
}
void k0(){
    ll res=0;
    sort(g+1,g+m+1,cmp);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        ll u=g[i].u,v=g[i].v,w=g[i].w;
        if(find(u)!=find(v)){
            f[find(u)]=find(v);
            ans+=w;
            res++;
            if(res==n-1) return ;
        }
    }
}
void k1(){
    ll res=0;
    sort(g+1,g+m+1,cmp);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        ll u=g[i].u,v=g[i].v,w=g[i].w;
        if(find(u)!=find(v)){
            f[find(u)]=find(v);
            res++;
            ggg[res].u=u,ggg[res].v=v,ggg[res].w=w;
            if(res==n-1) return ;
        }
    }
}
void kk(ll h){
    ll res=0;
    for(int i=1;i<=l;i++) {
        gg[i].u=g[i].u;
        gg[i].v=g[i].v;
        gg[i].w=g[i].w;
    }
    sort(gg+1,gg+l+1,cmp);
    for(int i=1;i<=h;i++) f[i]=i;
    for(int i=1;i<=l;i++){
        ll u=gg[i].u,v=gg[i].v,w=gg[i].w;
        if(find(u)!=find(v)){
            f[find(u)]=find(v);
            cnt+=w;
            res++;
            if(res==h-1) return ;
        }
    }
}
void dfs(ll ce){
    if(ce==k+1){
        cnt=0;
        ll op=n+1;
        l=m;
        for(int i=1;i<=k;i++){
            //cout<<t[i]<<" ";
            if(t[i]==1){
                cnt+=cc[i];
                for(int j=1;j<=n;j++){
                    g[++l].u=op;
                    g[l].v=j;
                    g[l].w=c[i][j];
                }
                op++;
            }
        }

        kk(op-1);//cout<<cnt<<endl;
        ans=min(ans,cnt);
        return ;
    }
    t[ce]=1;
    dfs(ce+1);
    t[ce]=0;
    dfs(ce+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    if(k==0){
        ans=0;
        k0();
        cout<<ans;
        return 0;
    }
    k1();
    for(int i=1;i<=n-1;i++){
        g[i].u=ggg[i].u;
        g[i].v=ggg[i].v;
        g[i].w=ggg[i].w;
    }
    m=n-1;
    bool f=0;
    l=m;
    for(int i=1;i<=k;i++){
        cin>>cc[i];
        bool flag=1;
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]!=0) flag=0;
        }
        if(flag==1&&c[i]==0) f=1;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
