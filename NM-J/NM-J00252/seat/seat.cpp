#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], x;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for ( int i = 1; i <= n * m; i++ )
        scanf("%d", &a[i]);
    x = a[1];
    sort(a + 1, a + n * m + 1);
    int i = n * m, y = 1, z = 1;
    while(a[i] != x){
        if ( z % 2 == 1 ){
            if ( y == n )
                z++;
            else
                y++;
        }
        else{
            if ( y == 1 )
                z++;
            else
                y--;
        }
        i--;
    }
    printf("%d %d", z, y);
    return 0;
}
