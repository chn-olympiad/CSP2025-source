#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,k,fa[(int)1e7+6];
struct node{
    int u,v,w;
}q[(int)1e7+5];
bool cmp(node x,node y){
    return x.w < y.w;
}
int finds(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x] = finds(fa[x]);
}
void merge(int x,int y){
    fa[finds(x)] = fa[finds(y)];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i<=n+k;i++){
        fa[i] = i;
    }
    for(int i = 1;i<=m;i++){
        cin >> q[i].u >> q[i].v >> q[i].w;
    }

    long long pos = m;
    for(int i = 1;i<=k;i++){
        int t;
        cin >> t;
        for(int j = 1;j<=n;j++){
            int w;
            cin >> w;
            pos++;
            q[pos]={i+n,j,w};
        }
    }
    sort(q+1,q+pos+1,cmp);
    for(int i = 1;i<=pos;i++){
        if(finds(q[i].u)!=finds(q[i].v)){
            ans+=q[i].w;
            merge(q[i].u,q[i].v);
        }
    }
    cout << ans << '\n';
    return 0;
}
