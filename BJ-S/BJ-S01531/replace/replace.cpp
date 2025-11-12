#include <bits/stdc++.h>
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull mul=257;
il int read(){
    int x=0,c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=2e5+5,M=7e6+5;
int n,m,k,q,len[N],pos[N],ans[N];char s1[M],s2[M];char s[M],t[M];
ull pw[M];int L;
struct node{
    char s[M];ull h[M];
    il node(){}
    il ull geth(int l,int r){return h[r]-h[l-1]*pw[r-l+1];}
    il void init(int len){
        h[0]=0;
        for(int i=1;i<=len;++i) h[i]=h[i-1]*mul+s[i];
    }
}A,B;
ull h1[N],h2[N];
#define pii pair<ull,ull>
#define fi first
#define se second
map<pii,int> mp;
pii a[N],b[N];int to1[N],to2[N],tot;
struct TRIE{
    int t[M][26],cnt,p1[N],p2[N];
    int dfn[M],siz[M],tot;
    il TRIE(){cnt=tot=0;}
    il int insert(char s[],int len){
        int x=0,c;
        for(int i=1;i<=len;++i){
            c=s[i]-'a';
            if(!t[x][c]) t[x][c]=++cnt;
            x=t[x][c];
        }
        return x;
    }
    void dfs(int x){
        int y;dfn[x]=++tot,siz[x]=1;
        for(int i=0;i<26;++i){
            y=t[x][i];if(!y) continue;
            dfs(y),siz[x]+=siz[y];
        }
    }
    il int ck(int x,int y){return dfn[x]>=dfn[y] && dfn[x]<=dfn[y]+siz[y]-1;}
}C,D;
char tmp[M];
int cc[N],dd[N];
#define P pair<int,int>
vector<int> e[N<<1],g[N<<1];
vector<P> E[N*3],G[N*3];
int X[N<<2],Y[N<<2];
struct BIT{
    int t[N<<2];
    il BIT(){memset(t,0,sizeof(t));}
    il void add(int x,int v){while(x) t[x]+=v,x-=(x&-x);}
    il int get(int x){int ret=0;while(x<=k) ret+=t[x],x+=(x&-x);return ret;}
}T;
int x,y,z,u,v,w;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&q);pw[0]=1ull;for(int i=1;i<M;++i) pw[i]=pw[i-1]*mul;
    for(int i=1;i<=n;++i){
        scanf("%s%s",s+1,t+1);
        len[i]=strlen(s+1),pos[i]=L+1;
        for(int j=L+1;j<=L+len[i];++j) A.s[j]=s[j-L],B.s[j]=t[j-L];
        L+=len[i];
    }L=pos[n]+len[n]-1;
    A.init(L),B.init(L);
    for(int i=1;i<=n;++i){
        x=pos[i]+len[i],y=pos[i]-1;
        for(int j=pos[i];j<pos[i]+len[i];++j) if(A.s[j]!=B.s[j]) {x=j;break;}
        for(int j=pos[i]+len[i]-1;j>=pos[i];--j) if(A.s[j]!=B.s[j]){y=j;break;}
        if(x==pos[i]+len[i]){cc[i]=1;continue;}
        //if(i==3) puts("*");
        a[i]={A.geth(x,y),B.geth(x,y)};
        if(!mp.count(a[i])) mp[a[i]]=++tot;to1[i]=mp[a[i]];
        u=0;for(int j=x-1;j>=pos[i];--j) tmp[++u]=A.s[j];
        v=C.insert(tmp,u),C.p1[i]=v;
        u=0;for(int j=y+1;j<=pos[i]+len[i]-1;++j) tmp[++u]=A.s[j];
        v=D.insert(tmp,u),D.p1[i]=v;
    }
    for(int i=1;i<=q;++i){
        scanf("%s%s",s+1,t+1);m=strlen(s+1),k=strlen(t+1);ans[i]=0;
        if(m!=k){dd[i]=1;continue;}
        x=y=0;for(int j=1;j<=m;++j) if(s[j]!=t[j]){x=j;break;}
        for(int j=m;j;--j) if(s[j]!=t[j]) {y=j;break;}
        ull u=0,v=0;
        for(int j=x;j<=y;++j) u=u*mul+s[j],v=v*mul+t[j];
        b[i]={u,v};if(!mp.count(b[i])) mp[b[i]]=++tot;
        to2[i]=mp[b[i]];
        u=0;for(int j=x-1;j>=1;--j) tmp[++u]=s[j];
        v=C.insert(tmp,u),C.p2[i]=v;
        u=0;for(int j=y+1;j<=m;++j) tmp[++u]=s[j];
        v=D.insert(tmp,u),D.p2[i]=v;
    }
    C.dfs(0),D.dfs(0);
    for(int i=1;i<=n;++i){
        if(cc[i]) continue;
        /*x=C.p1[i],y=D.p1[i];
        int l1=C.dfn[x],r1=C.dfn[x]+C.siz[x]-1;
        int l2=D.dfn[y],r2=D.dfn[y]+D.siz[y]-1;*/
        e[to1[i]].push_back(i);
    }
    for(int i=1;i<=q;++i){
        if(dd[i]) continue;
        g[to2[i]].push_back(i);
    }
    for(int i=1;i<=tot;++i){
        if(!e[i].size() || !g[i].size()) continue;
        //printf("*** %d\n",i);
        m=k=0;int l1,r1,l2,r2;
        for(int u:e[i]){
            x=C.p1[u],y=D.p1[u];
            int l1=C.dfn[x],r1=C.dfn[x]+C.siz[x]-1;
            int l2=D.dfn[y],r2=D.dfn[y]+D.siz[y]-1;
            X[++m]=l1-1,X[++m]=r1;
            Y[++k]=l2-1,Y[++k]=r2;
            //printf("*** %d %d %d %d\n",l1,r1,l2,r2);
        }
        for(int u:g[i]){
            x=C.p2[u],y=D.p2[u];
            X[++m]=C.dfn[x],Y[++k]=D.dfn[y];
            //printf("* %d %d\n",C.dfn[x],D.dfn[y]);
        }
        sort(X+1,X+1+m);m=unique(X+1,X+1+m)-X-1;
        sort(Y+1,Y+1+k);k=unique(Y+1,Y+1+k)-Y-1;
        for(int u:e[i]){
            x=C.p1[u],y=D.p1[u];
            int l1=C.dfn[x],r1=C.dfn[x]+C.siz[x]-1;
            int l2=D.dfn[y],r2=D.dfn[y]+D.siz[y]-1;
            l1=lower_bound(X+1,X+1+m,l1)-X,r1=lower_bound(X+1,X+1+m,r1)-X;
            l2=lower_bound(Y+1,Y+1+k,l2)-Y,r2=lower_bound(Y+1,Y+1+k,r2)-Y;
            E[r1].push_back({r2,1});
            E[l1-1].push_back({l2-1,1});
            E[r1].push_back({l2-1,-1});
            E[l1-1].push_back({r2,-1});
        }
        for(int u:g[i]){
            x=C.p2[u],y=D.p2[u],x=C.dfn[x],y=D.dfn[y];
            x=lower_bound(X+1,X+1+m,x)-X;
            y=lower_bound(Y+1,Y+1+k,y)-Y;
            G[x].push_back({y,u});
        }
        for(int j=0;j<=k;++j) T.t[j]=0;
        for(int j=m;j;--j){
            for(auto it:E[j]) T.add(it.fi,it.se);
            for(auto it:G[j]) ans[it.se]+=T.get(it.fi);
        }
        for(int j=0;j<=k;++j) T.t[j]=0;
        for(int j=0;j<=m;++j) E[j].clear(),G[j].clear();
    }
    for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
    return 0;
}
