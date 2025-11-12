#include<bits/stdc++.h>
using namespace std;
int aa[500005][25];
int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    long long n , k;
    cin >> n >> k;
    long long a[500005] = {};
    long long b[25] = {};
    b[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= 20; i++){
        b[i] = b[i-1] * 2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 20; j >= 0; j--){
            if(a[i]/b[j] == 1){
                aa[i][j] = 1;
                a[i] %= b[j];
            }
        }
    }
    for(int j = 20; j >= 0; j--){
        for(int i = 1; i <= n; i++){
                aa[i][j] += aa[i-1][j];
                //cout << aa[i][j] << " ";
        }
    }
    int cnt = 1;
    int num = 0;
    for(int i = 1; i <= n; i++){
        for(int j = cnt;j <= i;j++){
           int sum = 0;
            for(int h = 0; h <= 20; h++){
                sum += (aa[i][h] - aa[j-1][h])%2*b[h];
            }
            //
            cout << sum << " ";
            if(sum == k){
                num++;
                cnt = i + 1;
                break;
            }
        }
    }
    cout << num;
    return 0;
}
