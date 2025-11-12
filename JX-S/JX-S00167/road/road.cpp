#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
struct edge{
    int x,y;ll z;
    bool operator <(const edge a)const{
        return z<a.z;
    }
}e[N],tmp[N],t[11][10008];
ll w[N];
int n,m,k,fa[N],E[N],cnt,num,p[N],id[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
ll ans;
int main(){
    //freopen("input.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;ll z;scanf("%d%d%lld",&x,&y,&z);
        e[i]=edge{x,y,z};
    }
    for(int i=0;i<k;i++){
        scanf("%lld",&w[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&t[i][j].z);
            t[i][j].y=j;t[i][j].x=n+i+1;
        }
    }
    sort(e+1,e+m+1);
    for(int i=0;i<k;i++)
    sort(t[i]+1,t[i]+n+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=find(e[i].x),y=find(e[i].y);
        if(x==y)continue;E[++cnt]=i;
        ans+=e[i].z;fa[x]=y;
    }
    E[++cnt]=m+1;
    e[m+1].x=e[m+1].y=1;e[m+1].z=2e18;
    for(int S=1;S<(1<<k)-1;S++){
        int cc=0,tot=0;ll ss=0;
        for(int i=0;i<k;i++)
        if((S>>i)&1)cc++,id[cc]=i,p[cc]=0,ss+=w[i];
        for(int i=1;i<=n+k;i++)fa[i]=i;
        for(int j=1;j<=cnt;j++){
            num=0;int g=E[j];
            for(int z=1;z<=cc;z++)
            while(p[z]<n&&t[id[z]][p[z]+1].z<=e[g].z)p[z]++,tmp[++num]=t[id[z]][p[z]];
            sort(tmp+1,tmp+num+1);
            for(int z=1;z<=num;z++){
                int x=find(tmp[z].x),y=find(tmp[z].y);
                if(x==y)continue;ss+=tmp[z].z;fa[x]=y;
                tot++;if(tot==n+cc-1)break;
            }
            int x=find(e[g].x),y=find(e[g].y);
            if(x!=y)ss+=e[g].z,fa[x]=y,tot++;
            if(tot==n+cc-1)break;
        }
        ans=min(ans,ss);
    }
    printf("%lld\n",ans);
    return 0;
}