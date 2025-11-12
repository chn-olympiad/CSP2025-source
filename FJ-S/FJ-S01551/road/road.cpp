#include<bits/stdc++.h>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
struct node{
    long long u,v,w;
};
node e[1000010];
long long n,m,k,ans,tmp,dlta,cnt,anss,kk=1;
long long c[20],fa[10010],flag[10010],bj[10010],bjn[10010],a[20][10010];
long long num,nxt[220010],first[220010],to[220010],val[220010];
long long read(){
    long long x=0;char ac=getchar();
    while(ac<'0' || ac>'9') ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x;
}
void add(long long a,long long b,long long c){
    num++;
    to[num]=b;
    nxt[num]=first[a];
    first[a]=num;
    val[num]=c;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
long long find(long long x){
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
bool Union(long long a,long long b){
    long long x=find(a),y=find(b);
    if(x==y) return 0;
    fa[x]=y;return 1;
}
void work(){
    sort(e+1,e+m+1,cmp);
    for(long long i=1;i<=m;i++)
        if(Union(e[i].u,e[i].v))
            ans+=e[i].w,add(e[i].u,e[i].v,e[i].w),add(e[i].v,e[i].u,e[i].w);
}
void dfs(long long u,long long fa,long long dn){
    bj[u]=a[kk][u],bjn[u]=u;
    for(long long i=first[u];i;i=nxt[i]){
        if(to[i]==fa || val[i]==-1) continue;
        dfs(to[i],u,dn);
        if(bj[to[i]]<bj[u]) bj[u]=bj[to[i]],bjn[u]=to[i];
        if(u==dn) cnt+=(val[i]-bj[to[i]]);
            /*,printf("test edge : %lld %lld %lld\n",bjn[v],val[i],bj[v])*/
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(long long i=1;i<=m;i++)
        e[i].u=read(),e[i].v=read(),e[i].w=read();
    for(long long i=1;i<=k;i++){
        c[i]=read();
        for(long long j=1;j<=n;j++)
            a[i][j]=read();
    }
    for(long long i=1;i<=n;i++)
        fa[i]=i;
    work(),anss=ans;
    // printf("test : %lld\n",ans);
    while(kk<=k){
        tmp=dlta=0;
        // printf("test < %lld > :\n",kk);
        for(long long i=1;i<=n;i++){
            if(flag[i]) continue;
            cnt=0,dfs(i,0,i);
            if(cnt-c[kk]-a[kk][i]>=dlta) dlta=cnt-c[kk]-a[kk][i],tmp=i;
            // printf("%lld %lld\n",i,cnt-c[kk]-a[kk][i]);
        }
        // printf("tmp : %lld\ndlta : %lld\n",tmp,dlta);
        if(!tmp) break;
        flag[tmp]=1,ans-=dlta,kk++,anss=min(anss,ans);
        for(long long i=first[tmp];i;i=nxt[i])
            val[i]=-1,add(tmp,bjn[to[i]],bj[to[i]]),add(bjn[to[i]],tmp,bj[to[i]]);
        // printf("%lld %lld %lld\n",kk-1,anss,ans);
    }
    // printf("%lld\n",kk);
    return !printf("%lld",anss);
}