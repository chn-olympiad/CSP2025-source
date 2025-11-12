#include <bits/stdc++.h>
using namespace std;

int ans, n, k;
int xor_sum[500005];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    int x;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        xor_sum[i] = xor_sum[i-1]^x;
    }
    //start from "start_point", and then MEIJU the points after it
    //if there is a point that can make sum == k, let its next point become "start_point"
    //if there is no a point that can make sum == k, make "start_point" the next point
    int start_point = 1;
    int chosen_point;
    while (start_point <= n){
        chosen_point = start_point;
        for (int i = start_point; i <= n; i++){
            if ((xor_sum[i] ^ xor_sum[start_point-1]) == k){
                chosen_point = i;
                ans ++;
                break;
            }
        }
        start_point = chosen_point+1;

    }
    printf("%d", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
  value = 100 110 011 101
xor_sum = 100 010 001 100
value[2]^value[1] =?= xor_sum[2]^xor_sum[0]
101 = 101
!!!!!OK!!!!!But how?
Plan A: Just MEIJU all. How??????????????
*/
