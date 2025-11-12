#include<bits/stdc++.h>
#define N 10010
#define M 2000010
#define ll long long
using namespace std;
int n,m,K,c[N];
int pre[N];
bool vis[N];
ll ans;
struct E{int u,v,w;} e[M];
int read(){
    int f=1,x=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')    f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return f*x;
}

int find(int x){
    if(pre[x]==x)   return x;
    else return pre[x]=find(pre[x]);
}

bool cmp(E x,E y){
    return x.w<y.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),K=read();
    for(int i=1;i<=n+K;i++){
        pre[i]=i;
    }
    for(int i=1;i<=m;i++){
        e[i].u=read();
        e[i].v=read();
        e[i].w=read();
    }
    int idx=m;
    int ww;
    for(int i=1;i<=K;i++){
        c[n+i]=read();
        for(int j=1;j<=n;j++){
            ww=read();
                e[++idx].u=n+i;
                e[idx].w=ww;
                e[idx].v=j;
        }
    }
    //cout<<idx<<" ";
    n+=K;
    sort(e+1,e+idx+1,cmp);
    int cnt=0;
    for(int i=1;i<=idx;i++){
        if(cnt==n-1)    break;
        int fa1=find(e[i].u);
        int fa2=find(e[i].v);
        if(fa1==fa2)    continue;
        pre[fa1]=fa2;
        if(e[i].u<=n && e[i].v<=n) cnt++;
        //cout<<e[i].w<<" ";
        ans+=e[i].w;
        if(e[i].u>n && !vis[e[i].u]) ans+=c[e[i].u],vis[e[i].u]=0;

    }
    cout<<ans;
    return 0;
}
