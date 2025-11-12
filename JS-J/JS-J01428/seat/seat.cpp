#include<bits/stdc++.h>
#define maxn 105

int m, n;
int a, cnt;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat,out", "w", stdout);
    scanf("%d%d%d", &m ,&n, &a);
    cnt = 1;
    for(int i = 2; i <= m * n; i++){
        int cur;
        scanf("%d", &cur);
        if(cur >= a) cnt++;
    }

    //printf("cnt = %d\n", cnt);

    int x, y;
    if(x % n){
        x = cnt / n + 1;
        int dist = cnt % n;
        if(x % 2) y = dist;
        else y = n - dist + 1;
    }else{
        x = cnt / n;
        y = n;
    }

    printf("%d %d\n", x, y);
    return 0;
}
