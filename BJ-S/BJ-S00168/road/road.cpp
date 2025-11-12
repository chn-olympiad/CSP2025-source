#include <bits/stdc++.h>
using namespace std;
long long n,m,k,idx,head[1000000],c,dis[1000000],vis[1000000],q[1000000],h[1000000],ans;
struct d{
    long long u,v,w,nxt;
}a[3000000];
void add(long long u,long long v,long long w){
    a[++idx].u=u;
    a[idx].v=v;
    a[idx].w=w;
    a[idx].nxt=head[u];
    head[u]=idx;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=0;i<m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    long long n1=n;
    for(int i=0;i<k;i++){
        cin>>c;
        long long co;
        if(c==0){
            n1++;
            for(int j=1;j<=n;j++){
                cin>>co;
                add(n1,i,co);
                add(i,n1,co);
            }
        }
        else for(int i=0;i<n;i++) cin>>co;
    }
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1]=0;
    long long s=1;
    for(int i=1;i<n1;i++){
        vis[s]=1;
        h[a[q[s]].u]=s;
        ans+=a[q[s]].w;
        for(int j=head[s];j!=0;j=a[j].nxt){
            if(vis[a[j].v]==0&&dis[a[j].v]>=dis[s]+a[j].w){
                dis[a[j].v]=dis[s]+a[j].w;
                q[a[j].v]=j;
            }
        }
        long long mn=9000000000000000000;
        for(int j=1;j<=n1;j++){
            if(vis[j]==0&&dis[j]<mn){
                mn=dis[j];
                s=j;
            }
        }
    }
    for(int i=n+1;i<=n1;i++){
        if(h[i]==0) ans-=a[q[i]].w;
    }
    cout<<ans;
    return 0;
}
