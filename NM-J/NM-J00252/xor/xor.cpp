#include <bits/stdc++.h>
using namespace std;
int n, k, a[500100], ans;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for ( int i = 1; i <= n; i++ )
        scanf("%d", &a[i]);
    for ( int i = 1; i <= n; i++ ){
        int x = i, z = 0;
        while(x < n){
            int y = a[x];
            for ( int j = x + 1; j <= n; j++, x++ ){
                if ( a[j] == k ){
                    if ( a[j + 1] == k )
                        x--;
                    x += 2, z++;
                    break;
                }
                if ( y == k ){
                    x++, z++;
                    break;
                }
                y ^= a[j];
                if ( y == k ){
                    x++, z++;
                    break;
                }
            }
        }
        ans = max(ans, z);
    }
    printf("%d", ans);
    return 0;
}
