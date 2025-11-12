#include<bits/stdc++.h>

using namespace std;

int n, a[5001], ans = 0;
bool t[5001];

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if(n < 3){
        printf("0");
        return;
    }
    if(n == 3 && a[1] + a[2] + a[3] > 2 * max(a[1], a[2], a[3])){
        printf("1");
    }
    return 0;
}
