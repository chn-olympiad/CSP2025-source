#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=2e6+5;
struct edge{
    int u,v;
    ll w;
    friend bool operator<(edge x,edge y){
        return x.w>y.w;
    }
}E[M];
int n,m,k,x,y,z,f[N],c[N],bzy,flg=0,aa[N][15],cj[15],MMb[15],xz[15],cnt=0;
ll ans=0,res=0;
edge e;
priority_queue<edge> q;
int find(int u){
    if(f[u]==u) return u;
    return f[u]=find(f[u]);
}
void hb(int u,int v){
    f[find(u)]=find(v);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        f[i]=i;
    }
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&y,&z);
        e.u=x;
        e.v=y;
        e.w=z;
        E[i]=e;
        q.push(e);
    }
    for(int i=1;i<=k;++i){
        scanf("%d",&bzy);
        cj[i]=bzy;
        if(bzy!=0) flg=1;
        for(int j=1;j<=n;++j){
            scanf("%d",&c[j]);
            aa[j][i]=c[j];
        }
        if(flg==0){
            for(int j=1;j<=n;++j){
                if(c[j]==0){
                    for(int au=1;au<=n;++au){
                        if(au==j) continue;
                        e.u=au;
                        e.v=j;
                        e.w=c[au];
                        q.push(e);
                    }
                    break;
                }
            }
        }

    }
    if(flg==0){
        while(q.size()){
            e=q.top();
            //cout<<e.w<<endl;
            q.pop();
            if(find(e.u)==find(e.v)) continue;
            hb(e.u,e.v);
            ans+=e.w;
        }
    }else{
        //cout<<"wudi"<<endl;
        while(q.size()){
            e=q.top();
            //cout<<e.w<<endl;
            q.pop();
            if(find(e.u)==find(e.v)) continue;
            hb(e.u,e.v);
            ans+=e.w;
        }
        srand(time(0));
        for(int i=1;i<=k;++i) MMb[i]=i;
        random_shuffle(MMb+1,MMb+k+1);
        for(int i=1;i<=k;++i){
            res=0;
            x=MMb[i];
            for(int j=1;j<=m;++j) q.push(E[j]);
            for(int j=1;j<=n+2;++j){
                f[j]=j;
            }
            for(int j=1;j<=n;++j){
                e.u=n+1;
                e.v=j;
                e.w=aa[j][x];
                q.push(e);
            }
            e.u=n+1;
            e.v=n+2;
            e.w=cj[x];
            q.push(e);
            while(q.size()){
                e=q.top();
                //cout<<e.w<<endl;
                q.pop();
                if(find(e.u)==find(e.v)) continue;
                hb(e.u,e.v);
                res+=e.w;
            }
            if(res<ans) xz[++cnt]=x;
            ans=min(ans,res);
        }
        //cout<<xz[1]<<endl;
        for(int j=1;j<=n+2*cnt;++j){
            f[j]=j;
        }
        for(int j=1;j<=m;++j) q.push(E[j]);
        for(int i=0;i<cnt;++i){
            for(int j=1;j<=n;++j){
                e.u=n+2*i+1;
                e.v=j;
                e.w=aa[j][xz[i+1]];
                q.push(e);
            }
            e.u=n+2*i+1;
            e.v=n+2*i+2;
            e.w=cj[xz[i+1]];
            q.push(e);
        }
        res=0;
        while(q.size()){
            e=q.top();
            //cout<<e.w<<endl;
            q.pop();
            if(find(e.u)==find(e.v)) continue;
            hb(e.u,e.v);
            res+=e.w;
        }
        //cout<<res<<endl;
        ans=min(ans,res);
    }

    cout<<ans;
    return 0;
}
