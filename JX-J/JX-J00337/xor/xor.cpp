#include<bits/stdc++.h>

using namespace std;

int n, k, ans = 0;
int a[500010];
bool t = 0;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ){
        int sum;
        for(int j = i; j <= n; j++){
            if(j == i)
                sum = a[j];
            else
                sum = sum ^ a[j];
            if(sum == k){
                ans++;
                i = j + 1;
                t = 1;
                break;
            }
        }
        if(!t)
            i++;
        else
            t = 0;

    }
    printf("%d", ans);
    return 0;
}
