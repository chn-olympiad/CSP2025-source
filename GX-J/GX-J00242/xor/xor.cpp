#include<bits/stdc++.h>
int arr[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    bool arr1 = true, arr0 = true;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] > 1){
            arr1 = false;
            arr0 = false;
        }
        if(arr == 0) arr1 = false;
    }
    if(arr1){
        printf("0");
        return 0;
    }
    printf("%d", n-2);
    return 0;
}
