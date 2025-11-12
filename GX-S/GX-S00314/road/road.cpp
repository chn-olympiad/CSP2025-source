#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+20,M=2e6+10;//wrong 2!
struct L{
    int u,v,w;
    bool operator<(const L &other)const{
        return w<other.w;
    }
};


int n,m,k,fa[N],tot,cnt,c[15],flag,nw[15][N];
int pt[15];
ll ans;
L tmp[M],ln[M];//enough?


int read(){
    int res=0; char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+(ch-'0'), ch=getchar();
    return res;
}

int Get(int x){
    if(x==fa[x])return x;
    return fa[x]=Get(fa[x]);
}

void dfs(int dep){
    if(dep>k){
        // clear
        for(int i=1;i<=n+k;i++)fa[i]=i;
        ll res=0;
        cnt=tot;
        for(int i=1;i<=m;i++)tmp[i]=ln[i];
        // add edge
        for(int i=1;i<=k;i++){
            if(!pt[i])continue;
            res+=c[i];
            for(int j=1;j<=n;j++)tmp[++cnt]={n+i,j,nw[i][j]};
        }
        // run
        sort(tmp+1,tmp+cnt+1);
        for(int i=1;i<=cnt;i++){
            int x=tmp[i].u, y=tmp[i].v, w=tmp[i].w;
            if(Get(x)==Get(y))continue;
            fa[fa[x]]=fa[y];
            res+=w;
        }
        ans=min(ans,res);
        return;
    }
    pt[dep]=0; dfs(dep+1);
    pt[dep]=1; dfs(dep+1);
}

void sub1(){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++)ln[++tot]={n+i,j,nw[i][j]};
    }
    sort(ln+1,ln+tot+1);
    for(int i=1;i<=tot;i++){
        int x=ln[i].u, y=ln[i].v, w=ln[i].w;
        if(Get(x)==Get(y))continue;
        fa[fa[x]]=fa[y];
        ans+=w;
    }
    printf("%lld",ans);
}

void sub2(){
    ans=1e18;
    dfs(1);
    printf("%lld",ans);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //scanf("%d%d%d",&n,&m,&k);
    n=read(); m=read(); k=read();
    for(int i=1;i<=m;i++){//wrong 1
        int u,v,w;
        //scanf("%d%d%d",&u,&v,&w);
        u=read(); v=read(); w=read();
        ln[++tot]={u,v,w};
    }
    for(int i=1;i<=k;i++){
        int eg=0;
        for(int j=1;j<=n+1;j++){
            int val; //scanf("%d",&val);
            val=read();
            //pd
            if(j==1){
                c[i]=val;
                if(val)flag=1;
                continue;
            }
            else if(!val)eg=1;
            //ln[++tot]={n+i,j-1,val};
            nw[i][j-1]=val;
        }
        if(!eg)flag=1;
    }

    if(!flag)sub1();
    else sub2();
    return 0;
}
