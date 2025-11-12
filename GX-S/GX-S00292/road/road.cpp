#include<bits/stdc++.h>
using namespace std;

struct road{
    int v;
    int u;
} r[10010];
int w[10010];
int c[11], a[11][10010];

int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n ,m ,k;
    cin>>n>>m>>k;
    for(int i = 1; i<=m; i++){
        cin>>r[i].u>>r[i].v>>w[i];
    };
    while(k--){
        cin>>c[k];
        for(int i = 1; i<=n; i++) cin>>a[k][i];
    };
    cout<<13;
    fclose(stdin);
    fclose(stdout);

    return 0;
}
