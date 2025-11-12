#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<time.h>
#define ll long long
#define itn int
#define scf scanf
#define prf printf
#define gc getchar
#define pc putchar
#define fu(v,s,e) for(int v=s;v<=(e);v++)
#define fd(v,s,e) for(int v=s;v>=(e);v--)
using namespace std;
int _t;
inline int in(){
    itn x=0,f=1;
    char c=gc();
    while((c<'0'||c>'9')&&c!='-') c=gc();
    if(c=='-') f=-1,c=gc();
    while(c>='0'&&c<='9') x=x*10+c-'0',c=gc();
    return f*x;
}
void out(ll x){
    if(x>9) out(x/10);
    pc(x%10+'0');
}
inline void out(ll x,char c){
    out(x),pc(c);
}
struct edge{
    int u,v,w,t;
}e[1100005];
inline bool operator<(const edge &p,const edge &q){return p.w<q.w;}
int n,m,k,c[15],tot;
int id[15][1025],idt[15];
ll ans[1025],mn=0x3939393939393939;
int fa[1025][20005],cnt[1025];
inline int fnd(int t,int x){return fa[t][x]==x?x:(fa[t][x]=fnd(t,fa[t][x]));}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // _t=in();
    // while(_t--){
    // }
    n=in(),m=in(),k=in();
    fu(i,0,(1<<k)-1){
        fu(j,1,n+k) fa[i][j]=j;
        fu(j,1,k) if(i&(1<<(j-1))) id[j][++idt[j]]=i,cnt[i]--;
    }
    idt[0]=1<<k;
    fu(i,1,1<<k) id[0][i]=i-1;
    fu(i,1,m){
        int u=in(),v=in(),w=in();
        e[++tot]=edge{u,v,w,0};
    }
    fu(i,1,k){
        int c=in();
        fu(j,1,idt[i]) ans[id[i][j]]+=c;
        fu(j,1,n){
            int a=in();
            e[++tot]=edge{i+n,j,a,i};
        }
    }
    // cerr<<tot<<'\n';
    sort(e+1,e+1+tot);
    fu(hd,1,tot){
        int u=e[hd].u,v=e[hd].v,w=e[hd].w,t=e[hd].t;
        if(t==0&&fnd(0,u)==fnd(0,v)) continue;
        fu(i,1,idt[t]){
            int tt=id[t][i];
            int fu=fnd(tt,u),fv=fnd(tt,v);
            // cerr<<t<<' '<<tt<<' '<<u<<' '<<v<<' '<<w<<'\n';
            if(fu^fv) ans[tt]+=w,fa[tt][fv]=fu,cnt[tt]++;
        }
    }
    fu(i,0,(1<<k)-1) mn=min(mn,ans[i]);
    // fu(i,0,(1<<k)-1) if(cnt[i]!=n-1){
    //     cerr<<i<<' '<<cnt[i]<<' '<<ans[i]<<'\n';
    // }
    out(mn,'\n');
    // cerr<<'\n'<<clock()/1000.0<<"ms\n";
    return 0;
}
/*
cnm，并查集只初始化到n
*/