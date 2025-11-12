#include <bits/stdc++.h>
using namespace std;

int m, n, a[108], k, pos, c, r, cnt;

int cmp(const void *p1, const void *p2){
    int *a = (int *)p1;
    int *b = (int *)p2;
    if(*a < *b){
        return 1;
    }
    return 0;
}

int main(){
    #if 1
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    #endif
    scanf(" %d %d", &n, &m);
    scanf(" %d", &k);
    for(int i = 1; i <= ((n * m) - 1); i++){
        scanf(" %d", &a[i]);
    }
    a[n * m] = k;
    qsort(&a[1], n * m, 4, cmp);
    for(int i = 1; i <= (n * m); i++){
        if(a[i] == k){
            pos = i;
            break;
        }
    }
    //printf("%d\n", pos);
    c = ceil(double(pos) / double(n));
    r = pos - ((c - 1) * n);
    if(!(c & 1)){
        r = n - r + 1;
    }
    printf("%d %d\n", c, r);
    return 0;
}