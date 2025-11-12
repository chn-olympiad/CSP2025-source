#include<iostream>
#include<stdio.h>

using namespace std;

int n, m, a[110], x, y, seat;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n*m;i++){
        scanf("%d", a+i);
        if(a[i] > a[1]) seat++;
    }
    x = seat/n+1;
    if(x & 1) y = seat%n+1;
    else y = n - seat%n;
    printf("%d %d", x, y);
}
