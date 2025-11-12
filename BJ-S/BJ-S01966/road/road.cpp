#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int vs[10005];
int cnt;
long long a[15][10005];
struct edge{
    int to;
    long long l;
    int is;
};
edge izel[10005];
int in[10005];
vector<edge>e[10005];
void add(int u,int v,int w){
    e[u].push_back({v,w,0});
    e[v].push_back({u,w,0});
    return;
}
int ize(int u){
    int res=0,minl=1e9,F=0;
    for(int i=1;i<=n;i++){
        izel[i]={0,0,0};
        if(vs[i])continue;
        izel[i]={0,1000000000000000,0};
        for(int j=1;j<=k;j++){
            long long len=a[j][u]+a[j][0]+a[j][i];
            if(izel[i].l>len){
                izel[i]={i,len,k};
            }
        }
        if(izel[i].l<minl){
            minl=izel[i].l;
            res=i;
        }
    }
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i].to;
        if(vs[v]){
            e[u].erase(e[u].begin()+i);
            i--;
            continue;
        }
        e[u][i]=izel[v];
        if(res==v||F==0){
            res=i;
            F=1;
        }
        izel[v]={0,0,0};
    }
    for(int i=1;i<=n;i++){
        if(izel[i].l!=0){
            e[u].push_back(izel[i]);
            if(res==i&&F==0){
                res=e[u].size()-1;
                F=1;
            }
            izel[i]={0,0,0};
        }
    }
    return res;
}
void del(int u,int m,int v){
    for(int i=0;i<e[u].size();i++){
        if(vs[e[u][i].to])continue;
        if(e[u][i].is==m){
            e[u][i].l-=a[m][0];
            e[u][i].l-=a[m][u];
            e[u][i].is=0;
        }
    }
    a[m][0]=a[m][u]=0;
}
void solve(int u){
    edge nxe=e[u][ize(u)];
    int nx=nxe.to;
    ans+=nxe.l;
    vs[nx]=1;
    in[++cnt]=nx;
    if(nxe.is){
        del(u,nxe.is,nx);
    }
    while(cnt<n){
        nxe=e[in[cnt]][ize(in[cnt])];
        int st=in[cnt];
        for(int j=1;j<cnt;j++){
            for(int i=0;i<e[j].size();i++){
                int v=e[j][i].to;
                if(vs[v]){
                    e[j].erase(e[j].begin()+i);
                    i--;
                    continue;
                }
                if(e[j][i].l<nxe.l){
                    nxe=e[j][i];
                    st=j;
                }
            }
        }
        nx=nxe.to;
        ans+=nxe.l;
        vs[nx]=1;
        in[++cnt]=nx;
        if(nxe.is){
            del(st,nxe.is,nx);
        }
    }
    cout<<ans;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<=n;j++){
            cin>>a[i][j];
        }
    }
    vs[1]=1;
    in[++cnt]=1;
    solve(1);
    return 0;
}
