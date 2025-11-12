#include<bits/stdc++.h>
using namespace std;

const int N=1e4+4,M=1e6+4;
int n,m,k,f[N][N],p[N],sum;
struct ed{
    int u,v,w;
}e[N*N];

bool cmp(ed a,ed b){
    return a.w<b.w;
}

int fa(int x){
    if(p[x]==x) return x;
    return fa(p[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(f,0x3f,sizeof f);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        f[a][b]=f[b][a]=min(f[a][b],c);
    }
    for(int i=1;i<=k;i++){
        int a,b[N];
        cin>>a;
        for(int j=1;j<=n;j++) cin>>b[j];
        for(int j=1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                f[j][l]=f[l][j]=min(f[j][l],a+b[j]+b[l]);
            }
        }
    }
    int idx=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            e[idx].u=i,e[idx].v=j,e[idx].w=f[i][j];
            idx++;
        }
    }
    sort(e+1,e+idx,cmp);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<idx;i++){
        if(fa(e[i].u)!=fa(e[i].v)){
            p[fa(e[i].u)]=fa(e[i].v);
            sum+=e[i].w;
        }
    }
    cout<<sum;
    return 0;
}



























