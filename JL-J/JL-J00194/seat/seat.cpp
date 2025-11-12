#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int a;
    scanf("%d", &a);
    int num = 0;
    for(int i = 2; i <= n * m; i++){
        int x;
        scanf("%d", &x);
        if(x > a) num++;
    }
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1){
            for(int j = 1; j <= m; j++){
                if(num == 0){
                    printf("%d %d", i, j);
                    return 0;
                }
                num--;
            }
        }
        else{
            for(int j = m; j >= 1; j--){
                if(num == 0){
                    printf("%d %d", i, j);
                    return 0;
                }
                num--;
            }
        }
    }

    return 0;
}
