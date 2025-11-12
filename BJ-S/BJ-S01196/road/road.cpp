#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n, m, k, sum;
long long w[1000005];
signed main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 1; i = m; i++) {
        int u, v;
        cin>>u>>v>>w[i];
    }
    for(int i = 1; i <= k; i++) {
        int c;
        cin>>c;
        for(int j = 1; j <= m; j++) {
            int a;
            cin>>a;
        }
    }
    sort(w+1, w+1+m);
    for(int i = 1; i <= m-1; i++) {
        sum += w[i];
    }
    cout<<sum<<endl;
    return 0;
}