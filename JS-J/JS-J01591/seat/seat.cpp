#include <bits/stdc++.h>
using namespace std;
int a[200], n, m, s, c, r;
void f1(int &x, int &y){
    int t;
    if (x < y){
        t = x;
        x = y;
        y = t;
    }
}
void f2(){
    for (int i = 1; i < n * m; i++){
        for (int j = 1; j <= n * m - i; j++){
            f1(a[j], a[j + 1]);
        }
    }
}
int f3(){
    for (int i = 1; i <= n * m; i++){
        if (a[0] == a[i]) return i;
    }
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++){
        scanf("%d", &a[i]);
    }
    a[0] = a[1];
    f2();
    s = f3();
    c = (s - 1) / n + 1;
    if (c % 2 != 0){
        r = ((s - 1) % n) + 1;
    }
    else {
        r = n - ((s - 1) % n);
    }
    printf("%d %d", c, r);
    fclose(stdin);
    fclose(stdout);
}
