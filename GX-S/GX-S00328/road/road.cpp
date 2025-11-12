#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin >> n >> m >> k;
    int u[n+1],v[n+1],w[n+1];
    for(int i=1;i<=n;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    int cnt = 0;
    int t,ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(u[i] == v[j]) cnt++;
            if(cnt == n-2){
                t = i;
                break;
            }
        }
    }
    ans += w[t];
    for(int i=1;i<=n;i++){
        if(v[i] == u[t]) ans += w[i];
    }
    cout << ans;
    return 0;
}
