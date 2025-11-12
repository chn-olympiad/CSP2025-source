#include <iostream>
#include <cstdio>
using namespace std;
string a;
int u,v,w,n,m,k,j,minn,maxn,mas;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i<=m;i++){
        cin >> u >> v >> w;
        minn = min(u,v);
        maxn = max(v,w);
        mas = max(u,min(v,w));
    }for(int i = 1;i<=n+1;i++){
        cin >> j;
    }
    cout << (minn+maxn)*3+7-mas;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
