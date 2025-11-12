#include<bits/stdc++.h>
using namespace std;

int n,m,k;
struct s{
    int u,v,w;
}l[1000005];
struct x{
    int c,a[105];
}z[105];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i = 1;i<=m;i++){
        cin>>l[i].u>>l[i].v>>l[i].w;
    }
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=n;j++){
            cin>>z[i].c>>z[i].a[n];
        }
    }

    return 0;
}
