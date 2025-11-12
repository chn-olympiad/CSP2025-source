#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5,M=20;
int fa[M*N];
int find(int x){return fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=find(y);}
struct eg{
    int u,v,w;
    bool ir;
    bool operator<(const eg&o)const{return w<o.w;}
};
vector<eg> es;
int n,m,k,u,v,w,c,ans;
unordered_set<int> um;
int32_t main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    while(m--){
        cin >> u >> v >> w;
        es.push_back(eg{u,v,w,1});
    }
    for(int i=1;i<=k;i++){
        cin >> c;
        vector<int> tmp;
        tmp.reserve(n);
        for(int j=1;j<=n;j++){
            cin >> w;
            tmp.push_back(w);
        }
        for(int i=0;i<n;i++)for(int j=0;j<i;j++)if(i!=j)es.push_back(eg{i+1,j+1,tmp[i]+tmp[j],1});
    }
    sort(es.begin(),es.end());
    iota(fa,fa+n,0);
    for(int i=0,cnt=0;i<es.size();i++){
        if(find(es[i].u)!=find(es[i].v)){
            merge(es[i].u,es[i].v);
            //if(es[i].u<=n)um.insert(es[i].u);
            //if(es[i].v<=n)um.insert(es[i].v);
            cnt++;
            ans+=es[i].w;
            if(cnt==n-1)return cout << ans,0;
        }
    }
    return 0;
}
