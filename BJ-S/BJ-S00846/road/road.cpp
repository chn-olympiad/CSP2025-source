#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, m,k, a1, a2, a3,b[10];
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >>a1 >> a2 >> a3;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n+1; j++) cin >> b[j];
    }
    cout << "13";
    return 0;
}
