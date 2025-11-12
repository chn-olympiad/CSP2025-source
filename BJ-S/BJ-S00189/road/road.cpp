#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+25,M=1e6+5;
// bool stMEM;
struct edge{
    int u,v,w;
    bool operator<(edge &A)const {
        return w<A.w;
    }
}es[M],nds[1030][N],f[15][N],tmp[N];
int merge(int lst,int t,int n,int nw){
    int l=1,r=1,p=0;
    while(l<=t and r<=n){
        if(f[nw][r].w<=nds[lst][l].w){
            p++;tmp[p]=f[nw][r];r++;
        }
        else{
            p++;tmp[p]=nds[lst][l];l++;
        }
    }
    while(l<=t){p++;tmp[p]=nds[lst][l];l++;}
    while(r<=n){p++;tmp[p]=f[nw][r];r++;}
    return p;
}
int n,m,k;
int fa[N],ecnt[N];
ll ans[N],sc[N];
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}

int c[12];
// bool edMEM;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    // int T=clock();
    cin.tie(0)->sync_with_stdio(0);
    // cerr<<"memory used:"<<(&edMEM-&stMEM)/1048576<<"MB"<<endl;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>es[i].u>>es[i].v>>es[i].w;
    }
    sort(es+1,es+1+m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>f[i][j].w;
            f[i][j].u=i+n,f[i][j].v=j;
        }
        sort(f[i]+1,f[i]+1+n);
    }
    for(int i=1;i<=m;i++){
        if(find(es[i].u)!=find(es[i].v)){
            fa[find(es[i].u)]=find(es[i].v);
            ecnt[0]++;nds[0][ecnt[0]]=es[i];ans[0]+=es[i].w;
            if(ecnt[0]==n-1)break;
        }
    }
    ll mn=ans[0];
    for(int i=1;i<(1<<k);i++){
        int lst=i,ed;
        for(int j=0;j<k;j++){
            if(i&(1<<j)){
                lst-=(1<<j);
                sc[i]=sc[lst]+c[j+1];
                ans[i]=sc[i];
                ed=merge(lst,ecnt[lst],n,j+1);
                break;
            }
        }
        for(int j=1;j<=n+k;j++)fa[j]=j;
        for(int j=1;j<=ed;j++){
            // cerr<<tmp[j].u<<" "<<tmp[j].v<<" "<<tmp[j].w<<endl;
            if(find(tmp[j].u)!=find(tmp[j].v)){
                fa[find(tmp[j].u)]=find(tmp[j].v);
                ecnt[i]++;nds[i][ecnt[i]]=tmp[j];
                ans[i]+=tmp[j].w;
            }
        }
        // cerr<<ans[i]<<endl;
        mn=min(mn,ans[i]);
    }
    cout<<mn<<endl;
    // cerr<<(1.0*clock()-T)/CLOCKS_PER_SEC<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}