#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int x,y,z;
    bool operator <(Edge a){
        return z<a.z;
    }
}e[1000005],ne[110005];
int fa[10015],c[15];
inline int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,nm=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        int fax=findfa(e[i].x),fay=findfa(e[i].y);
        if(fax!=fay){
            fa[fax]=fay;
            ne[++nm]=e[i];
        }
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1,x;j<=n;j++){
            scanf("%d",&x);
            nm++;
            ne[nm].x=j;
            ne[nm].y=n+i;
            ne[nm].z=x;
        }
    }
    m=nm;
    for(int i=1;i<=m;i++){
        e[i]=ne[i];
    }
    sort(e+1,e+m+1);
    long long mi=1LL<<62;
    for(int i=0;i<1<<k;i++){
        long long sum=0;
        for(int j=1;j<=k;j++){
            if(i>>j-1&1){
                sum+=c[j];
            }
        }
        for(int j=1;j<=n+k;j++){
            fa[j]=j;
        }
        for(int j=1;j<=m;j++){
            if(e[j].y<=n||(i>>e[j].y-n-1&1)){
                int fax=findfa(e[j].x),fay=findfa(e[j].y);
                if(fax!=fay){
                    sum+=e[j].z;
                    fa[fax]=fay;
                }
            }
        }
        mi=min(mi,sum);
    }
    cout<<mi;

    return 0;
}
