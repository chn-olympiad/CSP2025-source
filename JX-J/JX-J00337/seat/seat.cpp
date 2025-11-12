#include<bits/stdc++.h>

using namespace std;

int n, m, a[110], b[11][11], k = 1;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n * m; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n*m; i++){
        int ma = 0, k1;
        for (int j = i; j <= n * m; j++){
            if(a[j] >= ma){
                ma = a[j];
                k1 = j;
            }
        }
        if(k1 == k)
            k = i;
        else if(k == i)
            k = k1;
        swap(a[i], a[k1]);
    }
    int sum = 1;
    for(int i = 1; i <= m; i++){
        if(i % 2 == 1)
            for(int j = 1; j <= n; j++){
                if(sum == k){
                    printf("%d %d", i, j);
                    return 0;
                }
                else
                    sum++;
            }
        else
            for(int j = n; j >= 1; j--){
                if(sum == k){
                    printf("%d %d", i, j);
                    return 0;
                }
                else
                    sum++;
            }
    }
    return 0;
}
