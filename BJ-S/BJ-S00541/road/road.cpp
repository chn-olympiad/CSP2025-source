#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e4+10,M=2e6+10;
int n,m,k,ans,c[20],a[20][N],pos[20];
int fa[N],sz[N];
struct Edge{int u,v,w;}e[M],E[N];
bool ch[20];
bool cmp(Edge x,Edge y){return  x.w<y.w;}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return;
    if(sz[x]>sz[y]){fa[y]=x;sz[x]+=sz[y];}
    else{fa[x]=y;sz[y]+=sz[x];}
}
void cal(){
    // for(int i=1;i<=k;i++)cout<<ch[i]<<" ";cout<<endl;
    int res=0,cnt=0,num=n;
    for(int i=1;i<=k;i++){
        if(!ch[i])continue;
        num++;res+=c[i];
        for(int j=1;j<=n;j++){
            E[++cnt]={n+i,j,a[i][j]};
        }
    }
    // cout<<m+cnt<<endl;
    sort(E+1,E+cnt+1,cmp);
    for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
    int ct=0,i=1,j=1;
    while(ct<num-1){
        while(i<=m&&find(e[i].u)==find(e[i].v))i++;
        while(j<=cnt&&find(E[j].u)==find(E[j].v))j++;
        if(i>m||(i<=m&&j<=cnt&&e[i].w>E[j].w)){
            // cout<<E[j].u<<" "<<E[j].v<<" "<<E[j].w<<" "<<find(E[j].u)<<" "<<find(E[j].v)<<endl;
            merge(E[j].u,E[j].v);
            res+=E[j].w;ct++;j++;
        }
        else{
            // cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<" "<<find(e[i].u)<<" "<<find(e[i].v)<<endl;
            merge(e[i].u,e[i].v);
            res+=e[i].w;ct++;i++;
        }
        // cout<<"!"<<" ";for(int i=1;i<=n+k;i++)cout<<find(i)<<" ";cout<<endl;
    }
    // cout<<res<<endl;
    ans=min(ans,res);
}
void dfs(int id){
    if(id>k){cal();return;}
    ch[id]=0;dfs(id+1);
    ch[id]=1;dfs(id+1);
}
int read(){
    char c=getchar();int d=0,fl=1;
    while(c>'9'||c<'0'){if(c=='-')fl=-1;c=getchar();}
    while(c>='0'&&c<='9'){d=d*10+c-'0';c=getchar();}
    return d*fl;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    int u,v,w;
    for(int i=1;i<=m;i++){
        u=read();v=read();w=read();
        e[i]={u,v,w};ans+=w;
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            a[i][j]=read();
            if(a[i][j]==0)pos[i]=j;
        }
    }
    if(k<=5){
        sort(e+1,e+m+1,cmp);
        dfs(1);
        printf("%lld\n",ans);
    }
    else{
        ans=0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(j==pos[i])continue;
                e[++m]={pos[i],j,a[i][j]};
            }
        }
        sort(e+1,e+m+1,cmp);
        for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
        int ct=0;
        for(int i=1;i<=m;i++){
            if(ct>=n-1)break;
            if(find(e[i].u)!=find(e[i].v)){
                merge(e[i].u,e[i].v);
                ans+=e[i].w;ct++;
            }
        }
        printf("%lld\n",ans);
    }
    // cerr<<clock()*1000.0/CLOCKS_PER_SEC<<endl;
    fclose(stdin);fclose(stdout);
    return 0;
}