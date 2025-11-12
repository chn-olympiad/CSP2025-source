#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n, m, k,u[1000005],v[1000005],w[1000005],suma=0;
    cin >> n >> m >> k;
    for(long long i = 1;i <= m;i++){
        cin >> u[i] >> v[i] >> w[i];
        suma+=w[i];
    }
    cout << suma;
    return 0;
}
