#include<bits/stdc++.h>
using namespace std;
bool AAA(int a, int b){
    return a > b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, a[10005], R = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n * m; i++){
        scanf("%d", &a[i]);
    }
    R = a[0];
    sort(a, a + (n * m), AAA);
    for(int i = 0; i < n * m; i++){
        if(R == a[i]){
            int x = i % n, y = i / n;
            if(y % 2 == 1){
                x = n - x - 1;
            }
            printf("%d %d", y + 1, x + 1);
            return 0;
        }
    }
    return 0;
}
