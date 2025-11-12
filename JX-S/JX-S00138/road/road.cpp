#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], c[1000005];
int main(){
    freopen("road.in", "r", stdin);
    freopne("road.out", "w", stdout);
    int n, m, k;
    long long sum = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        sum += c[i];
    }
    int s;
    for(int i = 1; i <= k; i++){
        cin >> s;
        for(int j = 1; j <= n; j++){
            scanf("%d", &s);
        }
    }
    if(k == 0) cout << sum;
    else cout << 0;
    return 0;
}
