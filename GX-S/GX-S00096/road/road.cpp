#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+10;

ll n,m,k;
ll c[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin >> u >> v >> w;
    }

    for(int i=1;i<=k;i++){
        ll a;
        cin >> c[i] >> a >> a >> a;
    }

    ll ans=0;
    for(int i=1;i<=k;i++){
        ans += c[i];
    }
    cout << ans;


    return 0;

}
