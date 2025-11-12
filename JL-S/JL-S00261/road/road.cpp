#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10009,M=1000009,P=110009;
int n,m,k,f[N],ff[N],c[15],cnt,q[15],len; ll ans,Ans;
int F(int x){return (x==f[x])?x:f[x]=F(f[x]);}
struct line{int u,v,w;}h[M],bus[12][N];
bool cmp(line a,line b){return a.w<b.w;}
int main(){
    int gg=clock();
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(register int i=1;i<=n;++i) f[i]=i;
    for(register int i=1;i<=m;++i)
        scanf("%d%d%d",&h[i].u,&h[i].v,&h[i].w);
    for(register int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(register int j=1;j<=n;++j) scanf("%d",&bus[i][j].w),bus[i][j].v=i+n,bus[i][j].u=j;
        sort(bus[i]+1,bus[i]+n+1,cmp);
    }
    sort(h+1,h+m+1,cmp);
    for(register int i=1;i<=m;++i) if(F(h[i].u)!=F(h[i].v))
        f[f[h[i].u]]=f[h[i].v],ans+=h[i].w,bus[0][++cnt]=h[i];
    for(register int it=1,idx,num,pos;it<(1<<k);++it){
        Ans=0,idx=0,num=0,len=1;
        for(register int i=1;i<=n+10;++i) f[i]=i;
        for(register int i=1;i<=k;++i) if((it>>(i-1))&1) Ans+=c[i],++num,q[++len]=i;
        for(register int i=0;i<=k;++i) ff[i]=1;
        while(idx<n+num-1){
            pos=-1;
            for(register int i=0;i<=len;i++) if(bus[q[i]][ff[q[i]]].u!=0)
                if(pos==-1||bus[pos][ff[pos]].w>bus[q[i]][ff[q[i]]].w) pos=q[i];
            if(F(bus[pos][ff[pos]].u)!=F(bus[pos][ff[pos]].v)){
                // printf("%d %d %d\n",bus[pos][ff[pos]].u,bus[pos][ff[pos]].v,bus[pos][ff[pos]].w);
                Ans+=bus[pos][ff[pos]].w;
                f[f[bus[pos][ff[pos]].u]]=f[bus[pos][ff[pos]].v];
                ++idx;
            }
            ++ff[pos];
        }
        ans=min(Ans,ans);
        // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
g++ -Wall -std=c++14 -O2 -fsanitize=address,undefined road.cpp -o road;./road

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/