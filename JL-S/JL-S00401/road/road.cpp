#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4+20;
const int M=1e6+1e5+5;
const LL inf=1e18;
int read(){
    int xx=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-48;ch=getchar();
    }
    return xx;
}
int n,m,k,f[N],c[15][N];LL ans=inf;
struct node{
    int x,y,w;
    bool operator <(const node &A) const{
        return w<A.w;
    }
};
node a[M],t[M];int cnt,num,x[15];LL d;
LL minn(LL x,LL y){return (x<y?x:y);}
int find(int x){return (f[x]==x?f[x]:f[x]=find(f[x]));}
void kruskal(){
    for(int i=1;i<=n+k;i++) f[i]=i;num=n;d=0;
    for(int i=1;i<=k;i++){
        if(!x[i]) continue;d+=c[i][0];
    }
    if(d>=ans) return;
    for(int i=1;i<=m;i++) t[i]=a[i];cnt=m;
    for(int i=1;i<=k;i++){
        if(!x[i]) continue;
        for(int j=1;j<=n;j++){
            t[cnt+j]={n+i,j,c[i][j]};
        }cnt+=n,num++;
    }
    sort(t+1,t+cnt+1);int sum=1;LL res=0;
    for(int i=1;i<=cnt&&sum<num;i++){
        int fx=find(t[i].x),fy=find(t[i].y);
        if(fx==fy) continue;
        f[fx]=fy,res+=t[i].w,sum++;
    }
    ans=minn(ans,res+d);
}
void dfs(int dep){
    if(dep==k+1){kruskal();return;}
    x[dep]=0,dfs(dep+1);
    x[dep]=1,dfs(dep+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        a[i].x=read(),a[i].y=read(),a[i].w=read();
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++) c[i][j]=read();
    }
    dfs(1);
    printf("%lld",ans);
    return 0;
}