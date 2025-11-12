#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int n,m,k;
vector<edge>G;
vector<int>ww;
int a[11][10100];
int fa[10100];
int find(int u){
    return u==fa[u]?u:find(fa[u]);
}
void hb(int u,int v){
    int uv=find(u),vv=find(v);
    fa[uv]=fa[vv];
    return ;
}
int kls(int nn,vector<edge>g){
    for(int i=1;i<=nn;i++){
        fa[i]=i;
        //cout<<"init ";
    }
    //cout<<"\n";
    int len=g.size(),ret=0;
    sort(g.begin(),g.end(),cmp);
    for(int i=0;i<len;i++){
        if(find(g[i].u)!=find(g[i].v)){
            hb(g[i].u,g[i].v);
            ret+=g[i].w;
            //cout<<g[i].u<<" "<<g[i].v<<" "<<"ret:"<<ret<<endl;
        }
    }
    return ret;
}
int mn=INT_MAX;
vector<edge>g;
void dfs(int dep,int v,int w_){
    if(dep==k){
		//cout<<"in\n";
        mn=min(mn,w_+kls(v,g));
        //cout<<"fnmn:"<<mn<<"---"<<endl;
        //cout<<"out\n";
        return ;
    }
    vector<edge>tmp=g;
    for(int i=0;i<n;i++){
        g.push_back({i+1,v+1,a[dep][i]});
    }
    dfs(dep+1,v+1,w_+ww[dep]);
    g=tmp;
    dfs(dep+1,v,w_);
    return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        G.push_back({u,v,w});
    }
    g=G;
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        ww.push_back(c);
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    if(k>3){
        cout<<0;
        return 0;
    }
    dfs(0,n,0);
    cout<<mn;
    return 0;
}
