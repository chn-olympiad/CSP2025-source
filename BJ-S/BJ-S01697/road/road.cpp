#include<bits/stdc++.h>
using namespace std;
const int N=1e4+50,M=1.3e6;
inline int read(){
    int x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')w=-1;
    for(;'0'<=ch&&ch<='9';ch=getchar())x=10*x+ch-'0';
    return x*w;
}
struct Edg{int u,v,w;}E[M];
int n,m,k,c[13],dad[N];
long long ans;
bool cmp(Edg a,Edg b){return a.w<b.w;}
int Find(int x){return x==dad[x]?x:dad[x]=Find(dad[x]);}
void Kruskal(){
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=n+k;++i)dad[i]=i;
    for(int i=1,fx,fy;i<=m;++i){
        fx=Find(E[i].u),fy=Find(E[i].v),
        fx!=fy?dad[fx]=fy,ans+=E[i].w:0;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;++i)E[i].u=read(),E[i].v=read(),E[i].w=read();
    for(int i=1;i<=k;++i){
        c[i]=read();
        for(int j=1;j<=n;++j)E[++m].u=j,E[m].v=n+i,E[m].w=read();
    }Kruskal();
    return printf("%lld\n",ans),0;
}