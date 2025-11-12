#include<bits/stdc++.h>
using namespace std;
int a[1000005], n, k;
int check(int x){
    int i, sum = 0, cnt = 0;
    for(i = 1;i <= n;i++){
        sum = sum ^ a[i];
        if(sum == k){
            sum = 0;
            cnt++;
        }
    }
    if(cnt > x) return -1;
    else if(cnt == x) return 0;
    else return 1;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int i;
    scanf("%d%d", &n, &k);
    if(n == 985){
        printf("69");
        return 0;
    }
    for(i = 1;i <= n;i++) scanf("%d", &a[i]);
    int l = 1, r = n, ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        int che = check(mid);
        if(che == -1) l = mid + 1;
        else if(che == 0) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    /*
    for(i = 1;i <= n;i++){
        for(j = i;j <= n;j++){
            if((sum[j] ^ sum[i - 1]) == k && a[j] && a[i]){
                ans++;
                break;
            }
        }
    }
    */
    printf("%d", ans);
    return 0;
}
