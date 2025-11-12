#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0){x=-x;putchar('-');}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int n,m,k;
struct Edge{
    int to,len;
    Edge(int x,int y){to=x;len=y;}
};
vector<Edge>edges[1001];
int c[11],a[11][10001];
namespace Sub1{
    struct Edges{
        int u,v,w;
        bool operator<(const Edges&A)const{return w<A.w;}
    }e[1000001];
    int fa[10001];
    inline int find_(int x){
        if(x==fa[x])return x;
        return fa[x]=find_(fa[x]);
    }
    inline int kruskal(){
        sort(e+1,e+m+1);
        int res=0;
        for(int i=1;i<=m;i++){
            int t1=find_(e[i].u),t2=find_(e[i].v);
            if(t1!=t2){
                fa[t1]=t2;
                res+=e[i].w;
            }
        }
        return res;
    }
    inline void main(){
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=m;i++){
            e[i].u=read();
            e[i].v=read();
            e[i].w=read();
        }
        write(kruskal());
    }
}
namespace Sub2{
    int len=0;
    struct Edges{
        int u,v,w;
        bool operator<(const Edges&A)const{return w<A.w;}
    }e[1000001];
    int fa[100001];
    inline int find_(int x){
        if(x==fa[x])return x;
        return fa[x]=find_(fa[x]);
    }
    inline int kruskal(){
        sort(e+1,e+len+1);
        int res=0;
        for(int i=1;i<=len;i++){
            int t1=find_(e[i].u),t2=find_(e[i].v);
            if(t1!=t2){
                fa[t1]=t2;
                res+=e[i].w;
            }
        }
        return res;
    }
    int f[2001][2001];
    inline void main(){
        for(int i=1;i<=n;i++)fa[i]=i;
        for(int i=1;i<=n+k;i++){
            for(int j=1;j<=n+k;j++){
                f[i][j]=1e18;
            }
        }
        for(int i=1;i<=n;i++){
            for(auto j:edges[i]){
                f[i][j.to]=j.len;
            }
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                f[n+i][j]=f[j][n+i]=a[i][j];
            }
        }
        for(int i=1;i<=n+k;i++){
            for(int j=1;j<=n+k;j++){
                if(i==j)f[i][j]=0;
            }
        }
        for(int K=k+1;K<=n+k;K++){
            for(int i=1;i<=n+k;i++){
                for(int j=1;j<=n+k;j++){
                    f[i][j]=min(f[i][j],f[i][K]+f[K][j]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(f[i][j]<1e18)e[++len]={i,j,f[i][j]};
            }
        }
        //cout<<len<<endl;
        write(kruskal());
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();m=read();k=read();
    Sub1::main();

    return 0;
}
