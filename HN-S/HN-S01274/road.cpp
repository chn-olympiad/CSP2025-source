#include<bits/stdc++.h>
using namespace std;
int fa[20010],w[20],a[20][20010],cnt;
struct ll{
    int x,y,w;
    bool operator<(const ll &a)const{
        return w<a.w;
    }
}c[1000010],c2[1500010],c3[1500010];
inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x;
}vector<ll>v;
int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n=read(),m=read(),k=read();
    long long ans=0;
    for(register int i=1;i<=n;i++)fa[i]=i;
    for(register int i=1;i<=m;i++){
            c[i].x=read(),c[i].y=read(),c[i].w=read();
    }sort(c+1,c+m+1);
    for(register int i=1;i<=m;i++){
        int tx=find(c[i].x),ty=find(c[i].y);
        if(tx!=ty){
            ans+=c[i].w;
            fa[tx]=ty;
            c2[++cnt]=c[i];
        }
    }for(register int i=0;i<k;i++){
        w[i]=read();
        for(register int j=1;j<=n;j++)a[i][j]=read();
    }for(register int i=1;i<(1<<k);i++){
        for(register int j=1;j<=cnt;j++)c3[j]=c2[j];
        int tot=cnt,ccnt=0;
        long long sum=0;
        for(register int j=0;j<k;j++){
            if((i>>j)&1){
                sum+=w[j];
                for(int k=1;k<=n;k++){
                    c3[++tot]={n+j+1,k,a[j][k]};
                }
            }
        }sort(c3+1,c3+tot+1);
        for(register int j=1;j<=n+k;j++)fa[j]=j;
        for(register int j=1;j<=tot;j++){
            int tx=find(c3[j].x),ty=find(c3[j].y);
            if(tx!=ty){
                fa[tx]=ty;
                ccnt++;
                sum+=c3[j].w;
            }if(ccnt==n+k-1)break;
        }ans=min(ans,sum);
    }printf("%lld",ans);
    return 0;
}
