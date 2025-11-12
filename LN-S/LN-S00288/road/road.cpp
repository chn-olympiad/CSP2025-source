#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1e4 + 7);
const int MAXM = (1e6 + 7);
namespace L1SkyL {
    void Main();
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    L1SkyL::Main();
    return 0;
}

namespace L1SkyL{
    int n,m,k;
    struct Edge{
        int from,to,val;
    }e[MAXM << 1];
    int Cnt;
    void Add(int from,int to,int val){
        e[++Cnt].to = to;
        e[Cnt].val = val;
        e[Cnt].from = from;
    }
    bool cmp(Edge a,Edge b){
        return a.val < b.val;
    }
    int fa[MAXN];
    int Find(int x){
        return fa[x] == x ? x : fa[x] = Find(fa[x]);
    }
    int Kruskal(){
        int cnt = 0,sum = 0;
        sort(e + 1,e + 1 + Cnt,cmp);
        for (int i = 1;i <= Cnt;++i){
            int x = Find(e[i].from),y = Find(e[i].to);
            if (x == y){
                continue;
            } 
            fa[x] = y;
            ++cnt,sum += e[i].val;
            if (cnt == n - 1){
                return sum;
            }
        }
    }
    void Main(){
        ios::sync_with_stdio(false); cin.tie(nullptr);
        cin >> n >> m >> k;
        for (int i = 1;i <= n;++i) fa[i] = i;
        for (int i = 1;i <= m;++i){
            int u,v,w;
            cin >> u >> v >> w;
            Add(u,v,w);
        }
        if (k == 0){
            cout << Kruskal() << "\n";
        }
    }
}