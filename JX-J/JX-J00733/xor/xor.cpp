#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5;
int num[maxn + 1];
bool b[maxn + 1] = {false};

int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    int n , k , cnt = 0;
    for (int i = 1 ; i <= n ; i += 1){
        b[i] = false;
    }
    scanf("%d%d" , &n , &k);
    for (int i = 1 ; i <= n ; i += 1){
        scanf("%d" , &num[i]);
    }
    for (int i = 1 ; i <= n ; i += 1){
        int tmp = num[i];
        for (int j = i ; j <= n ; j += 1){
            if (j != i){
                tmp ^= num[j];
            }
            if (b[i] == true || b[j] == true){
                break;
            }
            if (tmp == k){
                for (int ii = i ; ii <= j ; ii += 1){
                    b[ii] = true;
                }
                cnt += 1;
                break;
            }
        }
    }
    printf("%d" , cnt);
    return 0;
}
