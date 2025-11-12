#include<bits/stdc++.h>
#define Inf (1ll<<60)
#define inf 0x3f3f3f3f
#define For(i,s,t) for(int i=(s);i<=(t);++i)
#define Down(i,s,t) for(int i=(s);i>=(t);--i)
#define eps 1e-9
typedef long long ll;
typedef unsigned long long ull;
inline int max(int x,int y){return x>y ? x : y;}
inline int min(int x,int y){return x<y ? x : y;}
inline ll max(ll x,ll y){return x>y ? x : y;}
inline ll min(ll x,ll y){return x<y ? x : y;}
inline void ckmn(int &x,int y){x=min(x,y);}
inline void ckmx(int &x,int y){x=max(x,y);}
inline void ckmn(ll &x,ll y){x=min(x,y);}
inline void ckmx(ll &x,ll y){x=max(x,y);}
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || '9'<c) f=(c=='-' ? -1 : 1),c=getchar();
    while('0'<=c && c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f;
}
using namespace std;
const int M=2e5+100,N=5e6+100,k=131;
int n,q,tot,ans;
char s[N],s1[N];
struct Node{int l,r;ull lh,rh;}nw;
map<pair<ull,ull> ,int> rk;
vector<Node> t[M];
ull h,h1,pw[N],H[N];
ull Hash(int l,int r){
    return H[r]-H[l-1]*pw[r-l+1];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    n=read(),q=read();
    pw[0]=1;
    For(i,1,5e6) pw[i]=pw[i-1]*k;
    For(j,1,n){
        scanf("%s%s",s+1,s1+1);
        int pre=1,suf,len=strlen(s+1);
        suf=len;
        while(pre<=len && s[pre]==s1[pre]) ++pre;
        if(pre==len+1) continue;
        --pre;
        while(s[suf]==s1[suf]) --suf;
        ++suf;
        h=h1=0;
        For(i,pre+1,suf-1) h=k*h+s[i],h1=h1*k+s1[i];
        nw.l=pre,nw.r=len-suf+1;
        nw.lh=nw.rh=0;
        For(i,1,pre) nw.lh=k*nw.lh+s[i];
        For(i,suf,len) nw.rh=k*nw.rh+s[i];
        int &id=rk[make_pair(h,h1)];
        if(!id) id=++tot;
        t[id].push_back(nw);
    }
    For(j,1,q){
        scanf("%s%s",s+1,s1+1);
        int pre=1,suf,len=strlen(s+1);
        suf=len;
        while(pre<=len && s[pre]==s1[pre]) ++pre;
        --pre;
        while(s[suf]==s1[suf]) --suf;
        ++suf;
        h=h1=0;
        For(i,pre+1,suf-1) h=k*h+s[i],h1=h1*k+s1[i];
        int &id=rk[make_pair(h,h1)];
        if(!id){printf("0\n");continue;}
        // printf("[%d,%d]",pre+1,suf-1);
        ans=0;
        For(i,1,len) H[i]=H[i-1]*k+s[i];
        for(auto p : t[id]){
            // printf("%d %d %llu %llu %llu %llu\n",p.l,p.r,Hash(pre-p.l+1,pre),p.lh,Hash(suf,suf+p.r-1),p.rh);
            if(p.l<=pre && p.r<=len-suf+1 && (!p.l || Hash(pre-p.l+1,pre)==p.lh) && (!p.r || Hash(suf,suf+p.r-1)==p.rh))
                ++ans;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
