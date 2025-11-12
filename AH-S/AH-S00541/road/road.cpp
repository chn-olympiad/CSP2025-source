#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+15, M = 1.1e6+5;
ll n, m, k, fa[N], ans, tmp_cnt;
ll c[15], p[15][N];
struct Edge{
    ll u, v, w;
    bool operator <(const Edge &tmp){
        return w < tmp.w;
    }
}edge[M], tmp_edge[N*10];

inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
void init(){
    for(int i=1;i<=n+10;i++)fa[i] = i;
}
int find(int x){
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    fa[x] = y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(), m = read(), k = read();
    init();
    for(int i=1;i<=m;i++){
        edge[i] = Edge{read(), read(), read()};
    }
    bool flag = 1;
    for(int i=1;i<=k;i++){
        c[i] = read();
        if(c[i] != 0)flag = 0;
        for(int j=1;j<=n;j++)p[i][j] = read();
    }
    sort(edge+1, edge+m+1);
    if(k == 0){
        for(int i=1;i<=m;i++){
            if(find(edge[i].u) != find(edge[i].v)){
                unite(edge[i].u, edge[i].v);
                ans += edge[i].w;
            }
        }
        cout << ans;
    }else{
        ans = 0x3f3f3f3f3f3f3f;
        for(int i=0;i<(1<<k);i++){
            tmp_cnt = 0;
            ll sum = 0;
            init();
            for(int j=1;j<=k;j++){
                if(i & (1<<(j-1))){
                    sum += c[j];
                    for(int l=1;l<=n;l++){
                        tmp_edge[++tmp_cnt] = {n+j, l, p[j][l]};
                    }
                }
            }
            sort(tmp_edge+1, tmp_edge+tmp_cnt+1);
            int pos1 = 1, pos2 = 1;
            while(pos1 <= m && pos2 <= tmp_cnt){
                if(edge[pos1].w < tmp_edge[pos2].w){
                    if(find(edge[pos1].u) != find(edge[pos1].v)){
                        unite(edge[pos1].u, edge[pos1].v);
                        sum += edge[pos1].w;
                    }
                    pos1 ++;
                }else{
                    if(find(tmp_edge[pos2].u) != find(tmp_edge[pos2].v)){
                        unite(tmp_edge[pos2].u, tmp_edge[pos2].v);
                        sum += tmp_edge[pos2].w;
                    }
                    pos2++;
                }
            }
            while(pos1<=m){
                if(find(edge[pos1].u) != find(edge[pos1].v)){
                        unite(edge[pos1].u, edge[pos1].v);
                        sum += edge[pos1].w;
                    }
                    pos1 ++;
            }
            while(pos2<=tmp_cnt){
                if(find(tmp_edge[pos2].u) != find(tmp_edge[pos2].v)){
                        unite(tmp_edge[pos2].u, tmp_edge[pos2].v);
                        sum += tmp_edge[pos2].w;
                    }
                    pos2++;
            }
            ans = min(ans, sum);
        }
        cout << ans;
    }

    return 0;
}

/*
4 4 0
1 2 1
2 3 10
2 4 100
3 1 6

4 6 1
1 2 1
1 3 10
1 4 100
2 3 174
3 4 2375
4 4 213
0 100 100 20 0
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+15, M = 1.1e6+5;
ll n, m, k, fa[N], ans;
ll c[15], p[15][N];
struct Edge{
    ll u, v, w;
    bool operator <(const Edge &tmp){
        return w < tmp.w;
    }
}edge[M];

inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
void init(){
    for(int i=1;i<=n;i++)fa[i] = i;
}
int find(int x){
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)return;
    fa[x] = y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n = read(), m = read(), k = read();
    init();
    for(int i=1;i<=m;i++){
        edge[i] = Edge{read(), read(), read()};
    }
    bool flag = 1;
    for(int i=1;i<=k;i++){
        c[i] = read();
        if(c[i] != 0)flag = 0;
        for(int j=1;j<=n;j++)p[i][j] = read();
    }
    if(k == 0){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                edge[++m] = Edge{n+i, j, p[i][j]};
            }
        }
        sort(edge+1, edge+m+1);
        for(int i=1;i<=m;i++){
            if(find(edge[i].u) != find(edge[i].v)){
                unite(edge[i].u, edge[i].v);
                ans += edge[i].w;
            }
        }
        cout << ans;
    }else{

    }

    return 0;
}

*/




