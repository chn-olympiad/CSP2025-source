#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, a[105], c, r, rsc, pos;
bool cmp(int x, int y){
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n * m;i++) scanf("%d", &a[i]);
    rsc = a[1];
    sort(a + 1, a + 1 + (n * m), cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == rsc){
            pos = i;
            break;
        }
    }
    c = (int)ceil((double)pos / (double)n);
    if(c & 1) r = (pos - 1) % n + 1;
    else r = n - ((pos - 1) % n + 1) + 1;
    printf("%d %d\n", c, r);
    return 0;
}
