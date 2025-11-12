#include<bits/stdc++.h>
#define ll long long
const int N=5e6+5,M=5e6+5;
int n,m,k;
ll c[20],a[20][N];
int head[N],to[M],nex[M],pre[N],pw[N],et=1;
ll val[M];
ll ans,vill[20];
void add(int u,int v,ll w){
    nex[et]=head[u];
    head[u]=et;
    to[et]=v;
    val[et]=w;
    et++;
}
std::priority_queue<std::pair<ll,int>>q;
bool fl[N];
int las;
void f1(){
    //1 root
    q.push({0,1});
    while(q.size()&&las>0){
        ll d;
        int u;
        auto t=q.top();
        d=-t.first;
        u=t.second;
        q.pop();
        if(fl[u])continue;
        //printf("!!!!%lld %lld\n",u,d);
        if(u<=n){
            fl[u]=1;
            fl[2*n+u]=1;
            ans+=d;
            las--;
            for(int i=head[u];i;i=nex[i])if(fl[to[i]]==0){
                q.push({val[i],to[i]});
            }
        }
        else if(u<=2*n){
            vill[u-n]+=d;
            for(int i=head[u];i;i=nex[i])if(fl[to[i]]==0){
                //printf("@ %d\n",to[i]);
                q.push({val[i],to[i]+2*n});
                if(pre[to[i]]==0){
                    pre[to[i]]=u;
                    pw[to[i]]=val[i];
                }
                else if(-pw[to[i]]>-val[i]){
                    pre[to[i]]=u;
                    pw[to[i]]=val[i];
                }
            }
        }
        else{
            u-=2*n;
            fl[pre[u]]=1;
            fl[u]=1;
            fl[2*n+u]=1;
            //printf("%d\n",pre[u]-n);
            pre[u]=0;
            ans+=d;
            for(int i=head[u];i;i=nex[i])if(fl[to[i]]==0){
                q.push({val[i],to[i]});
            }
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        add(u,v,-w);
        add(v,u,-w);
    }
    for(int i=1;i<=k;i++){//village
        scanf("%lld",c+i);
        for(int j=1;j<=n;j++){//city
            scanf("%lld",&a[i][j]);
            add(n+i,j,-a[i][j]);
            //printf("!!!!!%d\n",et);
            add(j,n+i,-c[i]-a[i][j]);
        }
    }
    las=n;
    f1();
    for(int i=1;i<=k;i++)if(fl[i+n]){
        ans+=vill[i];
    }
    printf("%lld",ans);
}
