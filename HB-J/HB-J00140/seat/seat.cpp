#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
int R, R1;
int a[105];
int main(){
    freopen("seat.in", 'r', stdin);
    freopen("seat.out", 'w', stdout);
    scanf("%d%d", &n, &m);
    int le = n * m;
    for (int i = 1; i <= le; i ++)
        scanf("%d", &a[i]);
    R = a[1];
    sort(a + 1, a + le + 1);
    for (int i = le; i >= 1; i --){
        if (a[i] == R){
            R1 = le - i + 1;
            break;
        }
    }
    int r = 0, c = 0;
    if (R1 % n == 0){
        c = R1 / n;
        if (c % 2 == 0)
            r = n - ((R1 + 1) % n) - 1;
        else
            r = n - ((R1 - 1) % n) + 1;
    }
    else{
        c = R1 / n + 1;
        if (c % 2 == 0)
            r = n - (R1 % n) + 1;
        else
            r = n - (R1 % n) - 1;
    }
    printf("%d %d", c, r);
    return 0;
}
