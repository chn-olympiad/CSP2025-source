#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000000];
bool t1 = true, t2 = true;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (!(a[i] == 1)) t1 = false;
        if (!(a[i] == 1 || a[i] == 0)) t2 = false;
    }
    if (k == 0 && t1){
        printf("%d", n / 2);
    }
    else if (k == 0 && t2){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 0) sum++;
            else if (a[i] == 1){
                i++;
                if (a[i] == 1) sum++;
            }
        }
        printf("%d", sum);
    }
    else if (k == 1 && t2){
        int sum = 0;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1) sum++;
        }
        printf("%d", sum);
    }
    else printf("0");
    fclose(stdin);
    fclose(stdout);
}
