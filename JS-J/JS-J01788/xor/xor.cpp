#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 500010;
int n, k;
int a[maxn], b[maxn];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i] ^ b[i-1];
    }

    // k = 0 / 1, find first same / different
    int ans = 0;
    if (k == 1){
        for (int i=1; i<=n; i++){
            if (a[i] == 0){
                if (i < n && a[i+1] == 1){
                    ans++;
                    i++;
                }
            }
            if (a[i] == 1){
                if (i < n && a[i+1] == 0){
                    ans++;
                    i++;
                }
            }
        }
    }else{
        for (int i=1; i<=n; i++){
            if (a[i] == 0) ans++;
            if (a[i] == 1){
                if (i < n && a[i+1] == 1){
                    ans++;
                    i++;
                }
            }
        }
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
