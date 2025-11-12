#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define M 3000005
#define K 15
#define N 30005
#define ll long long
using namespace std;
int n,m,k,n2,m2,fa[N],sze[N];
struct edge{
    int u,v;
    ll w;
}b[M];
ll c[K],ans=1e18;
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void init(){
    for(int i=1;i<=n;i++) fa[i]=i,sze[i]=1;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    if(sze[x]<sze[y]) fa[x]=y;
    else fa[y]=x;
}
int pc(int x){
    int y=0;
    while(x) y++,x/=2;
    return y;
}
double cl1,cl2;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cl1=clock();
    scanf("%d%d%d",&n2,&m2,&k);
    for(int i=1,x,y,z;i<=m2;i++){
        scanf("%d%d%d",&x,&y,&z);
        b[i]=(edge){x,y,z};
    }
    m=m2;
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        b[++m]=(edge){n2+i*2-1,n2+i*2,c[i]};
        for(int j=1,x;j<=n2;j++){
            scanf("%d",&x);
            b[++m]=(edge){j,n2+i*2-1,x};
            b[++m]=(edge){j,n2+i*2,x};
        }
    }
    n=n2+k*2;
    sort(b+1,b+1+m,cmp);
    for(int ca=0;ca<(1<<k);ca++){
        //cout<<ca<<endl;
        ll ret=0,tar=n2+pc(ca)*2-1;
        init();
        for(int i=1;i<=k;i++){
            if((1<<(i-1))&ca){
                ret+=c[i],tar--;
                unite(n2+i*2-1,n2+i*2);
            }
        }
        if(ret>=ans) continue;
        for(int i=1;i<=m;i++){
            if(ret>=ans) break;
            //cout<<i<<"*****"<<endl;
            int xx=(b[i].u-n2+1)/2-1,yy=(b[i].v-n2+1)/2-1;
            if(xx>=0&&(((1<<xx)&ca)==0)) continue;
            if(yy>=0&&(((1<<yy)&ca)==0)) continue;
            //cout<<xx<<" "<<yy<<" "<<((1<<xx)&ca)<<" "<<((1<<yy)&ca)<<" ";
            if(find(b[i].u)!=find(b[i].v)){
                //cout<<b[i].u<<" "<<b[i].v<<" "<<ret<<" "<<tar<<endl;
                ret+=b[i].w;
                unite(b[i].u,b[i].v);
                tar--;
                if(tar==0) break;
            }
        }
        if(ret>=ans) continue;
        ans=ret;
        cl2=clock();
        if(cl2-cl1>=900000) break;
        //cout<<ret<<endl;
    }
    cout<<ans;
    return 0;
}
