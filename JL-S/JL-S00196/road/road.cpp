#include<bits/stdc++.h>
using namespace std;
const int N=5e6+1;
int n,m,k,f[N],c[11][N],d[11];
long long cnt=1e18;
struct node{
    int u,v,w;
}a[N],b[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
    return x;
}
int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
long long kruskal(int n,int m){
    long long ans=0;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        b[i].u=a[i].u;
        b[i].v=a[i].v;
        b[i].w=a[i].w;
    }
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=m;i++){
        int fx=find(b[i].u),fy=find(b[i].v);
        if(fx==fy) continue;
        f[fx]=fy;
        ans+=b[i].w;
    }
    return ans;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
        a[i].u=read();
        a[i].v=read();
        a[i].w=read();
    }
    bool boo=0;
    for(int i=1;i<=k;i++){
        d[i]=read();
        if(d[i]!=0) boo=1;
        for(int j=1;j<=n;j++) c[i][j]=read();
    }
    if(!boo){
        int l=m,r=n;
        for(int j=1;j<=k;j++) for(int p=1;p<=n;p++) a[++l]={n+j,p,c[j][p]};
        cout<<kruskal(n+k,l);
        return 0;
    }
    for(int i=0;i<min(3,(int)pow(2,k));i++){
        int l=m,r=n,s=i;
        long long cnt1=0;
        for(int j=1;j<=k;j++){
            if(s%2){
                r++;
                for(int p=1;p<=n;p++) a[++l]={r,p,c[j][p]};
                cnt1+=d[j];
            }
            s/=2;
        }
        cnt=min(cnt,kruskal(r,l)+cnt1);
    }
    cout<<cnt;
}
