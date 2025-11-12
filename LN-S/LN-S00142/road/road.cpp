
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
    int u,v,w;
};
Edge e1[20000100];
int city[20][10010],c[20];

int fa[10010];
int ufs_find(int x){
    if(fa[x] == x) return x;
    return fa[x] = ufs_find(fa[x]);
}
bool ufs_merge(int x,int y){
    int rx = ufs_find(x),ry = ufs_find(y);
    if(rx == ry) return false;
    fa[rx] = ry;
    return true;
}

bool cmp(Edge x,Edge y){
    return x.w<y.w;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        cin>>e1[i].u>>e1[i].v>>e1[i].w;
    }
    for(int i = 1;i<=k;i++){
            cin>>c[i];
        for(int j = 1;j<=n;j++){
            cin>>city[i][j];
        }
    }
    if(k == 0){
        int ans = 0;
        for(int i = 1;i<=n;i++){
            fa[i] = i;
        }
        sort(e1+1,e1+m+1,cmp);
        for(int i = 1;i<=m;i++){
            if(ufs_merge(e1[i].u,e1[i].v)){
                ans += e1[i].w;
            }
        }
        cout<<ans;
    }
    else if(c[1] == 0){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j) continue;
                int minw = 0x3f3f3f3f;
                m++;
                for(int x = 1;x<=k;x++){
                    e1[m].u = i;e1[m].v = j;
                    minw = min(city[x][i] + city[x][j],minw);
                }
                e1[m].w = minw;
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            fa[i] = i;
        }
        sort(e1+1,e1+m+1,cmp);
        for(int i = 1;i<=m;i++){
            if(ufs_merge(e1[i].u,e1[i].v)){
                ans += e1[i].w;
            }
        }
        cout<<ans;
    }
    return 0;
}

