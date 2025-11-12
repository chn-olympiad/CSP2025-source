#include <bits/stdc++.h>
using namespace std;
int read(){
    int xx=0,ff=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') ff=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        xx=xx*10+(ch-'0');
        ch=getchar();
    }
    return xx*ff;
}
void write(long long xx){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10) write(xx/10);
    putchar(xx%10+'0');
}
const int N=1e4,M=1e6;
const long long oo=1e18;
int n,m,k,w[15],a[15][N+5];
struct eee{
    int u,v,w;
}e[M+5],b[N*10+5],c[N*10+M+5];
bool cmp(eee A,eee B){
    return A.w<B.w;
}
int fa[N+5];
int fnd(int x){
    return (x==fa[x]?x:fa[x]=fnd(fa[x]));
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(); m=read(); k=read();
    for(int i=1;i<=m;++i){
        e[i].u=read(); e[i].v=read(); e[i].w=read();
    }
    sort(e+1,e+m+1,cmp);
    bool fl=1;
    for(int i=1;i<=k;++i){
        w[i]=read();
        for(int j=1;j<=n;++j) a[i][j]=read();
        if(w[i]) fl=0;
    }
    int sk=(1<<k); long long ans=oo;
    for(int s=0;s<sk;++s){
        if(fl && (s!=sk-1)) continue;
        int t=0,g=0; long long res=0;
        for(int i=1;i<=k;++i){
            if(((s>>(i-1))&1)){
                res+=w[i]; ++g;
                for(int j=1;j<=n;++j) b[++t]=(eee){n+g,j,a[i][j]};
            }
        }
        sort(b+1,b+t+1,cmp);
        int x=1,y=1,h=0;
        while(x<=m || y<=t){
            bool fl=0;
            if(x>m) fl=1;
            else if(y>t) fl=0;
            else{
                if(e[x].w<b[y].w) fl=0;
                else fl=1;
            }
            if(fl){
                c[++h]=b[y];
                ++y;
            }
            else{
                c[++h]=e[x];
                ++x;
            }
        }
        for(int i=1;i<=n+g;++i) fa[i]=i;
        int us=0;
        for(int i=1;us<n+g-1 && i<=h;++i){
            int fu=fnd(c[i].u),fv=fnd(c[i].v);
            if(fu!=fv){
                fa[fu]=fv;
                res+=c[i].w;
                ++us;
            }
        }
        ans=min(ans,res);
    }
    write(ans); putchar('\n');
    return 0;
}