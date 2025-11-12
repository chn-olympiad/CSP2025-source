#include <bits/stdc++.h>
using namespace std;

int a[1000008], tail;
char b[1000008];
long long k[12];

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
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    #endif
    scanf(" %s", &b[1]);
    tail = 0;
    for(int i = 1; i <= strlen(&b[1]); i++){
        if(b[i] >= '0' && b[i] <= '9'){
            a[++tail] = b[i] - '0';
            k[a[tail]]++;
        }
    }
    //qsort(&a[1], tail, 4, cmp);
    for(int i = 9; i >= 0; i--){
        for(long long j = 1; j <= k[i]; j++){
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}