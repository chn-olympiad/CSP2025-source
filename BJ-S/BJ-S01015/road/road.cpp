#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+35,M=1e6+5;
int n,m,k,c[15],a[15][N],fa[N],ans,cnt,res,cnt2,tot,val1[35],val2[35];
struct edge{
    int u,v,w;
}ed[M],e[M],lin[M];
vector<edge> vec[2][35];
int getfa(int x){
    if(x==fa[x]) return x;
    return fa[x]=getfa(fa[x]);
}
bool cmp(edge x,edge y){
    return x.w<y.w;
}
void kruskal(){
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x=ed[i].u,y=ed[i].v;
        int f1=getfa(x),f2=getfa(y);
        if(f1==f2) continue;
        e[++cnt]=ed[i];
        fa[f1]=f2; ans+=ed[i].w;
    }
}
void kruskal2(int typ,int val){
    int tmp=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=cnt2;i++){
        int x=e[i].u,y=e[i].v;
        int f1=getfa(x),f2=getfa(y);
        if(f1==f2) continue;
        vec[typ][val].push_back(e[i]);
        fa[f1]=f2; res+=e[i].w; ++tmp;
    }
}
void kruskal3(){
    int tmp=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=cnt2;i++){
        int x=e[i].u,y=e[i].v;
        int f1=getfa(x),f2=getfa(y);
        if(f1==f2) continue;
        fa[f1]=f2; res+=e[i].w; 
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>k; 
    for(int i=1;i<=m;i++){
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    sort(ed+1,ed+1+m,cmp);
    kruskal();
    /*cout<<"ans: "<<ans<<"\n";
    for(int i=1;i<=cnt;i++){
        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"\n";
    }*/
    //cout<<"????"<<ans<<"\n";
    for(int i=1;i<=cnt;i++) lin[i]=e[i];
    int kk=k/2; int mx=0;
    for(int i=1;i<(1<<kk);i++){
        res=0; cnt2=cnt;
        for(int j=1;j<=kk;j++){
            if((i>>(j-1))&1){
                res+=c[j];
                for(int l=1;l<=n;l++){
                    e[++cnt2]={l,n+j,a[j][l]};
                }
            }
        }
        val1[i]=res;
        sort(e+1,e+1+cnt2,cmp);
        kruskal2(0,i); ans=min(ans,res);
        cnt2=cnt;
        for(int j=1;j<=cnt;j++) e[j]=lin[j];
    }
    for(int i=1;i<(1<<(k-kk));i++){
        res=0; cnt2=cnt;
        for(int j=kk+1;j<=k;j++){
            if((i>>(j-1-kk))&1){
                res+=c[j];
                for(int l=1;l<=n;l++){
                    e[++cnt2]={l,n+j,a[j][l]};
                }
            }
        }
        val2[i]=res;
        mx=max(mx,cnt2);
        sort(e+1,e+1+cnt2,cmp);
        kruskal2(1,i); ans=min(ans,res);
        cnt2=cnt;
        for(int j=1;j<=cnt;j++) e[j]=lin[j];
    }
    for(int i=1;i<(1<<kk);i++){
        for(int j=1;j<(1<<(k-kk));j++){
            res=0; res=val1[i]+val2[j];
            cnt2=0;
            for(edge x:vec[0][i]) e[++cnt2]=x;
            for(edge x:vec[1][i]) e[++cnt2]=x;
            sort(e+1,e+1+cnt2,cmp); kruskal3();
            ans=min(ans,res); cnt2=0;
        }
    }
    cout<<ans;
    return 0;
}