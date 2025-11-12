#include<bits/stdc++.h>
using namespace std;
int n, m, r, a[110];
bool cmp(const int x, const int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n*m; i++) scanf("%d", &a[i]);
    r = a[1];
    sort(a+1, a+n*m+1, cmp);
    for(int i=1; i<=n*m; i++){
        if(a[i] == r){
            printf("%d", (i - 1) / n + 1);
            printf(" ");
            if((i - 1) / n % 2 == 0){
                if(i % n == 0) cout << n;
                else cout << i % n;
            }
            else{
                if(i % n == 0) cout << 1;
                else cout << n - i % n + 1;
            }
        }
    }
    return 0;
}
