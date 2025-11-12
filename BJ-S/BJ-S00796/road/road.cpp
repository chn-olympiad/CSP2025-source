#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 1e4 + 10,M = 1e6 + 10;
int n,m,k;
struct Edge{
    int u,v;
    LL w;
}edge[M];
int p[N];
bool cmp(Edge x,Edge y){
    return x.w < y.w;
}
int Find(int x){
    if(p[x] != x) p[x] = Find(p[x]);
    return p[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    if(k == 0){
        for(int i=1;i<=n;i++) p[i] = i;
        for(int i=1;i<=m;i++){
            int a,b;
            LL c;
            scanf("%d %d %lld",&a,&b,&c);
            edge[i].u = a;
            edge[i].v = b;
            edge[i].w = c;
        }
        sort(edge+1,edge+m+1,cmp);
        LL ans = 0;
        for(int i=1;i<=m;i++){
            int a = edge[i].u,b = edge[i].v;
            LL c = edge[i].w;
            a = Find(a),b = Find(b);
            if(a != b){
                ans += c;
                p[a] = b;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
