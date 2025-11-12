#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define lowbit(x) ((x)&(-(x)))
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
typedef long long ll;
const int mod=1e9+7,maxs=5e6+5,maxn=2e5+5;
inline ll read(){
    ll res=0,p=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')p=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+(c-'0');
        c=getchar();
    }
    return res*p;
}
struct modint{
    ll x;
    inline modint(ll x_){
        x=x_%mod;
    }
    inline modint operator+(modint b){
        return {(x+b.x)%mod};
    }
    inline modint operator-(modint b){
        return {(x-b.x%mod+mod)%mod};
    }
    inline modint operator*(modint b){
        return {(x*b.x)%mod};
    }
};
inline modint qpow(modint a,ll b){
    modint res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int ch[maxs][26],fail[maxs],al[maxs],sl[maxs],dfn[maxs],siz[maxs],sum[maxs],st[maxs],tp,tt,cn,ecnt,fcnt;
ll ans[maxn];
char s[maxn],s2[maxn];
struct node{
    int x,id,l,nxt;
}ae[maxs<<1];
struct edge{
    int v,nxt;
}af[maxs<<1];
int A[maxs],B[maxs],q[maxs],L[maxs],T[maxs];
inline int insert(int l){
    int cur=0;
    rep(v1,1,l){
        if(!ch[cur][s[v1]-'a']){
            ch[cur][s[v1]-'a']=++tt;
            al[tt]=al[cur]+1;
        }
        cur=ch[cur][s[v1]-'a'];
    }
    return cur;
}
inline void init(){
    int hd=1,tl=0;
    rep(v1,0,25)if(ch[0][v1])q[++tl]=ch[0][v1];
    while(hd<=tl){
        int cur=q[hd++];
        // printf("%d %d %d %d\n",fail[cur],cur,al[fail[cur]],al[cur]);
        af[++fcnt]={cur,T[fail[cur]]};
        T[fail[cur]]=fcnt;
        rep(v1,0,25){
            if(ch[cur][v1]){
                fail[ch[cur][v1]]=ch[fail[cur]][v1];
                q[++tl]=ch[cur][v1];
            }
            else ch[cur][v1]=ch[fail[cur]][v1];
        }
    }
}
inline void getdfn(int x){
    dfn[x]=++cn;
    siz[x]=1;
    for(int v1=T[x];v1;v1=af[v1].nxt){
        getdfn(af[v1].v);
        siz[x]+=siz[af[v1].v];
    }
}
inline void add(int pos,int v){
    for(int v1=pos;v1<=cn;v1+=lowbit(v1))sum[v1]+=v;
}
inline int query(int pos){
    int res=0;
    for(int v1=pos;v1;v1-=lowbit(v1))res+=sum[v1];
    return res;
}
inline void dfs(int x){
    st[++tp]=x;
    sl[tp]=al[x];
    // if(sl[tp-1]>=al[x])printf("cone\n");
    for(int v1=L[x],v=af[v1].v;v1;v1=af[v1].nxt,v=af[v1].v){
        add(dfn[v],1);
        add(dfn[v]+siz[v],-1);
    }
    for(int v1=A[x],tmp;v1;v1=tmp){
        tmp=ae[v1].nxt;
        if(al[x]<ae[v1].l)continue;
        int pos=lower_bound(sl+1,sl+tp+1,ae[v1].l)-sl-1;
        if(pos){
            ae[v1].nxt=B[st[pos]];
            B[st[pos]]=v1;
        }
        ans[ae[v1].id]+=query(dfn[ae[v1].x]);
    }
    for(int v1=T[x];v1;v1=af[v1].nxt)dfs(af[v1].v);
    for(int v1=B[x];v1;v1=ae[v1].nxt){
        ans[ae[v1].id]-=query(dfn[ae[v1].x]);
    }
    for(int v1=L[x],v=af[v1].v;v1;v1=af[v1].nxt,v=af[v1].v){
        add(dfn[v],-1);
        add(dfn[v]+siz[v],1);
    }
    tp--;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int in=read(),iq=read();
    rep(v1,1,in){
        scanf(" %s",s+1);
        int l=strlen(s+1);
        int p=insert(l);
        scanf(" %s",s+1);
        af[++fcnt]={insert(l),L[p]};
        L[p]=fcnt;
    }
    init();
    rep(v1,1,iq){
        scanf(" %s %s",s+1,s2+1);
        int l=strlen(s+1),lp=0,rp;
        rep(v2,1,l)if(s[v2]!=s2[v2]){
            if(!lp)lp=v2;
            rp=v2;
        }
        int cx=0,cy=0;
        rep(v2,1,l){
            cx=ch[cx][s[v2]-'a'];
            cy=ch[cy][s2[v2]-'a'];
            if(v2>=rp){
                ae[++ecnt]={cy,v1,v2-lp+1,A[cx]};
                A[cx]=ecnt;
            }
        }
    }
    getdfn(0);
    dfs(0);
    rep(v1,1,iq)printf("%lld\n",ans[v1]);
    return 0;
}