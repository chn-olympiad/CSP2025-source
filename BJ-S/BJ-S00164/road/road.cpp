#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
    cin >> n >> m >> k;
    long long sum = 0;
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >>u >> v >> w;
        sum += w;
    }
    cout << sum;
    return 0;
}
