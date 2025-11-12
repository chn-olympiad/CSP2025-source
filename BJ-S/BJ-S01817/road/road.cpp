#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
struct node{
int u,v,w;
}r[1000005];
int c,a[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++){
        cin >> r[i].u >> r[i].v >> r[i].w;
        ans += r[i].w;
    }
    for(int i = 1;i <= k;i++){
        cin >> c;
        for(int j = 1;j <= n;j++){
            cin >> a[i];
        }
    }
    cout << ans;
    return 0;
}
