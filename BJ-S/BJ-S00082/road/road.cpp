#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ll long long
#define ull long long
#define pb push_back
#define mk make_pair
#define fr first
#define se second
int read(){
    int n=0,fl=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-') fl=-1; 
        c=getchar();
    }
    while(isdigit(c)) n=n*10+c-'0',c=getchar();
    return n*fl;
}
void write(int n){
    if(n<0) putchar('-'),n=-n;
    int c[100]={},len=0;
    while(n) c[++len]=n%10,n/=10;
    for(int i=len;i;i--) putchar(c[i]+'0');
}
void writesp(int n){write(n),putchar(' ');}
void writeln(int n){write(n),putchar('\n');}
const int N=1e5+5,M=1e6+5;
int n,m,k,fa[N],siz[N];
void clear(){
    for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
}
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
bool merge(int x,int y){
    x=getfa(x),y=getfa(y);
    if(x==y) return 0;
    if(siz[x]>siz[y]) swap(x,y);
    fa[x]=y;
    siz[y]+=siz[x];
    return 1;
}
struct edge{
    int u,v,w;
}ed[M],a[15][N],ned[N];
int len,cnt[15],c[N];
bool cmp(edge x,edge y){return x.w<y.w;}
ll ans=0;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    clear();
    for(int i=1;i<=m;i++){
        ed[i].u=read();
        ed[i].v=read();
        ed[i].w=read();
    }
    sort(ed+1,ed+m+1,cmp);
    for(int i=1;i<=m;i++){
        assert(ed[i].u<=n+k);
        assert(ed[i].v<=n+k);
        if(merge(ed[i].u,ed[i].v)) ned[++len]=ed[i],ans+=ed[i].w;
        if(len==n-1) break;
    }
    for(int i=0;i<k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            int w=read();
            a[i][j].u=n+i+1;
            a[i][j].v=j;
            a[i][j].w=w;
        }
        sort(a[i]+1,a[i]+n+1,cmp);
    }
    for(int i=0;i<(1<<k);i++){
        len=0; 
        ll res=0;
        for(int j=0;j<=k;j++) cnt[j]=1;
        for(int j=0;j<k;j++){
            if((i>>j)&1) res+=c[j];
        } 
        clear();
        while(len<n+__builtin_popcount(i)-1){
            int id=k,tmp=ned[cnt[k]].w;
            if(cnt[k]>n-1) tmp=0x3f3f3f3f3f3f3f3f;
            for(int j=0;j<k;j++){
                if(((i>>j)&1)==0) continue;
                if(cnt[j]>n) continue;
                if(a[j][cnt[j]].w<tmp){
                    id=j; tmp=a[j][cnt[j]].w;
                }
            }
            int u=a[id][cnt[id]].u,v=a[id][cnt[id]].v;
            if(id==k) u=ned[cnt[k]].u,v=ned[cnt[k]].v;
            if(merge(u,v)) len++,res+=tmp;
            cnt[id]++;
        }
        ans=min(ans,res);
    }
    writeln(ans);
    return 0;
}