#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, cnt = 0, sum = 0, sw = 0;
    cin >> n >> k;
    int num[n + 5];
    int hr[n + 5]= {};
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(i == j){
                if(num[j] == k){
                    if(hr[i] == 0){
                        hr[i] += 1;
                        cnt++;
                    }
                }
            } else {
                for(int t = i + 1; t <= j; t++){
                    if(t == i + 1){
                        sum = num[t - 1] ^ num[t];
                    } else {
                        sum = (sum ^ num[t]);
                    }
                } if(sum == k){
                    sw = 0;
                    for(int t = i; t <= j; t++){
                        if(hr[t] != 0){
                            sw = 1;
                        }
                    }if(sw == 0){
                        for(int t = i; t <= j; t++){
                            hr[t] = 1;
                        } cnt++;
                    }
                }
            }
        }
    } cout << cnt;
    return 0;
}
