# include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int m[n + 5];
    for(int i = 2; i <= n; i++){
        scanf("%d", &m[i]);
    }
    int sum = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j + 1; k <= n; k++){
                for(int g = k + 1; g <= n; g++){
                    for(int l = g + 1; l <= n; l++){
                        if(m[k] + m[g] + m[l] > 2 * m[l]){
                            sum++;
                        }
                        if(m[j] + m[k] + m[g] + m[l] > 2 * m[l] && i == 0){
                            sum++;
                        }
                        if(m[i] + m[j] + m[k] + m[g] + m[l] > 2 * m[l]){
                            sum++;
                        }

                    }
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}
