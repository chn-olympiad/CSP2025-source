#include<bits/stdc++.h>
using namespace std;
#define se second
#define fi first
int n,m,k;
vector<pair<long long,pair<int,int> > > edge,tr,mer;
int fa[11010];
long long c[15],w[15][11010];
void init(){
    for(int i=0;i<=n+k+100;i++)
        fa[i]=i;
}
int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}
void merge(int x,int y){
    if(get(x)!=get(y))
        fa[get(x)]=get(y);
}

long long sol(int s){
    mer.clear();
    long long ans=0;
    mer=tr;
    for(int i=1;i<=k;i++)
        if((s>>(i-1))&1){
            ans+=c[i];
            for(int j=1;j<=n;j++)
                mer.push_back({w[i][j],{n+i+10,j}});
        }

    sort(mer.begin(),mer.end());
    init();
    for(auto e:mer){
        int x=e.se.fi,y=e.se.se,z=e.fi;
        if(get(x)!=get(y)){
            tr.push_back(e);
            merge(x,y);
            ans+=z;
        }
    }
    return ans;
}
bool ckA(){
    int flag=1;
    for(int i=1;i<=k;i++)
        if(c[i]!=0)flag=0;
    return flag;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge.push_back({z,{x,y}});
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        //printf("(%d)%lld\n",i,c[i]);
        for(int j=1;j<=n;j++)
            scanf("%lld",&w[i][j]);
    }
    sort(edge.begin(),edge.end());
    init();
    long long ans=0;
    for(auto e:edge){
        int x=e.se.fi,y=e.se.se,z=e.fi;
        if(get(x)!=get(y)){
            tr.push_back(e);
            merge(x,y);
            ans+=z;
        }
    }
    //printf("%lld\n",ans);
    if(ckA()){
        ans=min(ans,sol((1<<k)-1));
    }
    else{
        for(int i=1;i<(1<<k);i++){
            //printf("[%d]:%lld\n",i,sol(i));
            ans=min(ans,sol(i));
        }
    }
    printf("%lld\n",ans);
    return 0;
}