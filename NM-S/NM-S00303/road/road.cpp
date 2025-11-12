#include<bits/stdc++.h>
using namespace std;

int n, m, k, min1 = 1000000, min2 = 1000000;
int u[1001], v[1001], w[1001], c[11], a[11][2];

int main (){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
    }
    for(int j = 1; j <= k; j++){
        scanf("%d%d%d", &c[j], &a[j][0], &a[j][1]);
    }
    for(int i = 1; i <= m; i++){
        if(w[i] <= min1) min1 = w[i];
    }
    for(int i = 1; i <= k; i++){
        if(a[i][1] <= min2) min2 = a[i][1];
    }
    printf("%d", min1 + min2);
    return 0;
}
