#include<bits/stdc++.h>
using namespace std;
long long n, m, k, u[1000010], v[1000010], w[1000010], c, a, o;
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        cin>>u[i]>>v[i]>>w[i];
        o += u[i];
    }
    cin>>c>>a;
    cout<<o + c + a;
    return 0;
}
