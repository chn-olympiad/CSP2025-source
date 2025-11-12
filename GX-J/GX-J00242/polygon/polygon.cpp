#include<bits/stdc++.h>
using namespace std;
int m[5005];
long long c = 0;
void AAA(int n, int nm, int ii, int pos, int big, long long cpp){
    if(pos == nm){
        if(cpp > 2 * big){
            c++;
            c = c % 998244353;
        }
    }
    for(int i = ii + 1; i < n; i++){
        AAA(n, nm, i, pos + 1, max(big, m[i]), cpp + m[i]);
    }
    return;
}
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    for(int i = 3; i <= n; i++){
        AAA(n, i, -1, 0, -1, 0);
    }
    printf("%lld", c);
    return 0;
}
