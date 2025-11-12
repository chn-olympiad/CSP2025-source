#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k,num;
struct edge{
    int x,y,z,st;
    friend bool operator < (edge a,edge b){
        return a.z<b.z;
    }
}e[2000100];
int c[15],a[15][2010];
int fa[2010],ci;
int p[15],nump;
ll Mintree,ans;
inline int getroot(int x){
    if(fa[x]<0) return x;
    else return fa[x]=getroot(fa[x]);
}

inline void kruskal(int stas,int city){
    int fx,fy,tot=0;
    for(int i=1;i<=num;++i){
        if(e[i].st!=k+1 && ((stas&(1<<e[i].st))==0)) continue;
        fx=getroot(e[i].x);
        fy=getroot(e[i].y);
        if(fx!=fy){
            Mintree+=1LL*e[i].z;
            //cout<<e[i].x<<' '<<e[i].y<<' '<<e[i].z<<endl;
            fa[fx]=fy;
            tot++;
        }
        if(tot==city-1) return ;
    }
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
        e[i].st=k+1;
    }
    num=m;nump=0;
    for(int i=1;i<=k;++i){
        scanf("%d",&c[i]);
        if(c[i]!=0) nump++;
        for(int j=1;j<=n;++j){
            scanf("%d",&a[i][j]);
            num++;
            e[num].x=i+n,e[num].y=j,e[num].z=a[i][j];
            if(c[i]!=0){
                e[num].st=nump-1;
                p[nump]=i;
            }
            else e[num].st=k+1;
        }
    }
    sort(e+1,e+num+1);
    ans=0x3f3f3f3f3f3f3f3f;
    for(int sta=0;sta<(1<<nump);sta++){
        for(int i=1;i<=n+k;++i) fa[i]=-1;
        Mintree=0;ci=n+k-nump;
        for(int i=0;i<nump;++i){
            if(sta&(1<<i))
                Mintree+=1LL*c[p[i+1]],ci++;
        }
        kruskal(sta,ci);
        //cout<<Mintree;
        ans=min(ans,Mintree);
        //printf("State:%dAns:%d\n",sta,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
