#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int u,v,w;
    bool operator <(const edge&a) const{
        return w<a.w;
    }
};
vector <edge> vc[20],lv[40],rv[40];
int a[40],fa[300010],al[40],ar[40];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,k,ans=(int)1e18; cin>>n>>m>>k;
    for (int i=1; i<=m; i++){
        int u,v,w; cin>>u>>v>>w;
        vc[0].push_back(edge{u,v,w});
    }
    for (int i=1; i<=k; i++){
        cin>>a[i];
        for (int j=1; j<=n; j++){
            int x; cin>>x;
            vc[i].push_back(edge{j,i+n,x});
        }
    }
    for (int i=0; i<=k; i++){
        sort(vc[i].begin(),vc[i].end());
    }
    vector <edge> tmp;
    for (int i=1; i<=n+k; i++) fa[i]=i;
    for (auto x:vc[0]){
        if (find(x.u)!=find(x.v)){
            tmp.push_back(x);
            fa[find(x.u)]=find(x.v);
        }
    }
    vc[0]=tmp;
    int lft=k/2,rig=k-k/2;
    for (int i=0; i<(1<<lft); i++){
        for (int j=1; j<=n+k; j++)fa[j]=j;
        lv[i]=vc[0];
        for (int j=1; j<=lft; j++){
            if (i&(1<<j-1)){
                for (auto x:vc[j]) lv[i].push_back(x);
                al[i]+=a[j];
            }
        }
        sort(lv[i].begin(),lv[i].end());
        vector <edge> tmp;
        for (auto x:lv[i]){
            if (find(x.u)!=find(x.v)){
                tmp.push_back(x);
                fa[find(x.u)]=find(x.v);
            }
        }
        lv[i]=tmp;
    }
    for (int i=0; i<(1<<rig); i++){
        for (int j=1; j<=n+k; j++)fa[j]=j;
        for (int j=lft+1; j<=k; j++){
            if (i&(1<<j-lft-1)){
                for (auto x:vc[j]) rv[i].push_back(x);
                ar[i]+=a[j];
            }
        }
        sort(rv[i].begin(),rv[i].end());
        vector <edge> tmp;
        for (auto x:rv[i]){
            if (find(x.u)!=find(x.v)){
                tmp.push_back(x);
                fa[find(x.u)]=find(x.v);
            }
        }
        rv[i]=tmp;
    }

    for (int x=0; x<(1<<lft); x++){
        for (int y=0; y<(1<<rig); y++){
            for (int i=1; i<=n+k; i++) fa[i]=i;
            int tot=0,idx=0,idy=0,anss=al[x]+ar[y];
            //cout<<"--"<<x<<" "<<y<<" "<<anss<<"\n";
            while (idx!=lv[x].size()||idy!=rv[y].size()){
                if (idy==rv[y].size()||(idx!=lv[x].size()&&lv[x][idx].w<rv[y][idy].w)){
                    if (find(lv[x][idx].u)!=find(lv[x][idx].v)){
                        fa[find(lv[x][idx].u)]=find(lv[x][idx].v);
                        anss+=lv[x][idx].w;
                        //cout<<lv[x][idx].u<<" "<<lv[x][idx].v<<" "<<lv[x][idx].w<<"\n";
                    }idx++;
                }
                else{
                    if (find(rv[y][idy].u)!=find(rv[y][idy].v)){
                        fa[find(rv[y][idy].u)]=find(rv[y][idy].v);
                        anss+=rv[y][idy].w;
                        //cout<<rv[y][idy].u<<" "<<rv[y][idy].v<<" "<<rv[y][idy].w<<"\n";
                    }idy++;
                }
            }
            //cout<<"--"<<x<<" "<<y<<" "<<anss<<"\n";
            ans=min(ans,anss);
        }
    }

    cout<<ans;
}
