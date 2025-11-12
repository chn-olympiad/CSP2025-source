#include<bits/stdc++.h>
#define reg register
#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define il inline
using namespace std;
il int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')f=(ch=='-'?-1:f),ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=2e6+5;
int n,m,k,fa[N],a[N];
bool flag[N];
struct node{
    int u,v,w;
};
node rd[N],e[N];
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int x){
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(reg int i=1;i<=m;i++){
        rd[i].u=read();
        rd[i].v=read();
        rd[i].w=read();
    }
    sort(rd+1,rd+1+m,cmp);
    for(reg int i=1;i<=n;i++)
        fa[i]=i;
    int tot=0;ll ans=0;
    for(reg int i=1;i<=m;i++){
        int fau=find(rd[i].u);
        int fav=find(rd[i].v);
        if(fau==fav)
            continue;
        e[++tot]=rd[i];
        fa[fau]=fav;
        ans+=rd[i].w;
    }
    for(reg int i=1;i<=k;i++){
        a[i]=read();
        for(reg int j=1;j<=n;j++){
            e[++tot].u=j;
            e[tot].v=n+i;
            e[tot].w=read();
        }
    }
    sort(e+1,e+1+tot,cmp);
    for(reg int i=1;i<(1<<k);i++){
        for(reg int j=1;j<=k;j++)
            flag[j]=((i>>(j-1))%2);
        for(reg int j=1;j<=n+k;j++)
            fa[j]=j;
        ll res=0;
        for(reg int j=1;j<=tot;j++){
            if(e[j].v>n&&!flag[e[j].v-n])
                continue;
            int fau=find(e[j].u);
            int fav=find(e[j].v);
            if(fau==fav)continue;
            fa[fau]=fav;
            res+=e[j].w;
        }
        for(reg int j=1;j<=k;j++)
            res+=(ll)flag[j]*a[j];
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}
