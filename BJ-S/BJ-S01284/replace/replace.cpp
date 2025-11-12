#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a,ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <=m;i++){
        cin >> u >> v >> w;
        ans += w;
        }
    for(int j = 1;j <= k;j++){
        cin >> c;
        for(int i = 1;i <=c; i++){
            cin >> a;
        }
    }
    cout << ans;
    return 0;
}
