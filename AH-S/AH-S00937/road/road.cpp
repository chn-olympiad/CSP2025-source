#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7,M = 1e6 + 7;
struct node{
    int u,v,w;
}sd[M];
int fa[N];
int n,m,k;
int c[58],a[58][N];
bool cmp(node a,node b) { return a.w < b.w; }
int find(int x){
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x = find(x),y = find(y);
    fa[x] = y;
    return;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >>n >> m >> k;
    for(int i = 1;i <= m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        sd[i] = {u,v,w};
    }
    int op = m;
    for(int j = 1;j <= k;++j){
        cin >> c[j];
        int x,idx;
        for(int i = 1;i <= n;++i){
            scanf("%d",&a[j][i]);
            if(a[j][i] == 0) idx = i;
        }
        for(int i = 1;i <= n;++i){
            if(i == idx) continue;
            sd[++op] = {idx,i,a[j][i]};
        }
    }
    m = op;
    for(int i = 1;i <= n;++i) fa[i] = i;
    int cnt = 0,sum = 0;
    sort(sd+1,sd+1+m,cmp);
    for(int i = 1;i <= m;++i){
        if(cnt == n-1) break;
        auto t = sd[i];
        int U = find(t.u),V = find(t.v);
        if (U == V) continue;
        else{
            fa[U] = V;
            sum += t.w;
            ++cnt;
        }
    }
    cout << sum;
    return 0;
}
