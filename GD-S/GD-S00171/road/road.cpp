#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6 + 10, N = 1e4 + 100;

int n,m,k;
struct edge{
    int u,v;
    ll w;
};
int op[100];
int val[20][N];
vector <edge> e;
bool cmp(edge p,edge q){
    return p.w < q.w;
}
struct dsu{
    int fa[N];
    void clear(){
        for(int i=1;i<=n+k;i++){
            fa[i] = i;
        }
    }
    int find(int k){
        if(fa[k] != k) fa[k] = find(fa[k]);
        return fa[k];
    }
    void com(int p,int q){
        fa[p] = q;
    }
}D1;


void solve1(){
    D1.clear();
    sort(e.begin(),e.end(),cmp);
    ll ans = 0;
    for(auto i : e){
        int p = i.u, q = i.v;
        int f1 = D1.find(p);
        int f2 = D1.find(q);
        if(f1 == f2) continue;
        ans += i.w;
        D1.com(f1,f2);
    }
    cout<<ans;
    return;
}
void solve2(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            e.push_back({i + n,j,val[i][j]});
        }
    }
    solve1();
    return;
}


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>k;
    int u,v;
    ll w;
    bool fA = 1;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>op[i];
        if(op[i] != 0) fA = 0;
        bool res = 0;
        for(int j=1;j<=n;j++){
            cin>>val[i][j];
            if(val[i][j] == 0) res = 1;
        }
        if(res == 0) fA = 0;
    }
    if(k == 0) solve1();
    else if(fA) solve2();


    return 0;
}
