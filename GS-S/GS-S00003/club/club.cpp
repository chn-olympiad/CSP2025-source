#include <bits/stdc++.h>
using namespace std;
int t, n, a[100001], b[100001], c[100001], sum;
bool flagb, flagc;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        flagb = flagc = true;
        for (int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            if (b[i] != 0) flagb = false;
            if (c[i] != 0) flagc = false;
        }
        if (flagb && flagc){ // Sp A
            sort(a + 1, a + n + 1);
            for (int i = 1; i <= n / 2; i++) sum += a[i];
            printf("%d", sum);
            return 0;
        }
    }
    return 0;
}
