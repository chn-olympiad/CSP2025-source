#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>

#define LL long long
#define pLL pair<LL,LL>

using namespace std;

void FileIO(string File) {
    freopen((File+".in").c_str(),"r",stdin);
    freopen((File+".out").c_str(),"w",stdout);
}
LL read() {
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

const LL N=1e5+5;

LL T,n;
LL st,ed;
LL ans;
LL a[N][5];

LL head[N];
struct Edge {
    LL v,w,c,nxt;
} e[N*8+100];
void link(LL u,LL v,LL w,LL c) {
    e[++head[0]]=(Edge) {
        v,w,c,head[u]
    };
    head[u]=head[0];
}

LL fr[N];
LL vis[N];
LL dis[N];
LL flw[N];
priority_queue<pLL> p;
bool spfa() {
    for(int i=1;i<=n+8;i++) {
        dis[i]=-0x3f3f3f3f;
        fr[i]=0;
        vis[i]=false;
    }
    dis[st]=0;
    flw[st]=0x3f3f3f3f;
    p.push({0,st});
    vis[st]=true;
    while(!p.empty()) {
        LL u=p.top().second;
        LL uf=flw[u];
        p.pop();
        vis[u]=false;
        for(int i=head[u];i;i=e[i].nxt) {
            LL v=e[i].v;
            LL f=e[i].c;
            if(f==0) continue;
            if(dis[v]<dis[u]+e[i].w) {
                fr[v]=i;
                dis[v]=dis[u]+e[i].w;
                flw[v]=min(flw[u],f);
                if(!vis[v]) p.push({dis[v],v});
            }
        }
    }
    return dis[ed]!=-0x3f3f3f3f;
}
void update() {
    LL nw=ed;
    LL i=fr[nw];
    LL ni=((i-1)^1)+1;
    // printf("%lld %lld %lld,\n",e[i].v,e[i].w,e[i].c);
    // printf("%lld %lld %lld,\n",e[ni].v,e[ni].w,e[ni].c);
    while(nw!=st) {
        // printf("?%lld %lld\n",nw,fr[nw]);
        i=fr[nw];
        ni=((i-1)^1)+1;
        e[i].c-=flw[ed];
        ans+=e[i].w*flw[ed];
        e[ni].c+=flw[ed];
        nw=e[ni].v;
    }
}
void EK() {
    // printf("!%lld\n",dij());
    // for(int i=1;i<=n+5;i++) {
    //     printf("!%lld %lld %lld\n",flw[i],dis[i],fr[i]);
    // }
    // printf("//");
    while(spfa()) {
        // printf("!");
        update();
        // printf("%lld\n",dis[ed]);
    }
    // printf("\\");
}

int main() {
    FileIO("club");
    T=read();
    while(T--) {
        n=read();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=3;j++) {
                a[i][j]=read();
            }
        }
        // n+1 n+2 n+3
        st=n+4,ed=n+5;
        for(int i=1;i<=n;i++) {
            link(st,i,0,1);
            link(i,st,0,0);
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=3;j++) {
                link(i,n+j,a[i][j],1);
                link(n+j,i,-a[i][j],0);
            }
        }
        for(int i=1;i<=3;i++) {
            link(n+i,ed,0,n/2);
            link(ed,n+i,0,0);
        }
        EK();
        printf("%lld\n",ans);
        head[0]=0;
        for(int i=1;i<=n+8;i++) {
            head[i]=0;
        }
        ans=0;
    }
    return 0;
}

//? 神人网络流做法