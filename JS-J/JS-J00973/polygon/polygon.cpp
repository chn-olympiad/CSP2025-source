#include <iostream>
#include <algorithm>
using namespace std;

int n;
int len[10000];

// int prefix[10000];

// void init(){
//     prefix[0] = len[0];
//     for (int i = 1; i < n; i++){
//         prefix[i] = prefix[i-1] + len[i];
//     }
// }

// int sum(int l, int r){
//     if (l == 0){
//         return prefix[r];
//     }
//     return prefix[r] - prefix[l-1];
// }

bool calc(int n){
    
    int max_len = -2147483648;
    int i = 0;
    int one = 0;
    int sum = 0;
    while (n > 0){
        if (n % 2){
            one++;
            sum += len[i];
            max_len = max(max_len, len[i]);
        }
        n /= 2;
        i++;
    }
    if (one <= 2)
        return 0;
    if (sum <= max_len * 2)
        return 0;
    return 1;
}

int main(){

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);


    int ans = 0;
    cin >> n;

    bool all_one = 1;

    for (int i = 0; i < n; i++){
        cin >> len[i];
        if(len[i] != 1){
            all_one = 0;
        }
    }
    
    if (all_one){
        long long ans = 1;
        for (int i = 0; i < n; i++){
            ans = ans * 2 % 998244353LL;
        }
        ans -= n * (n-1) / 2;
        ans -= n;
        ans -= 1;
        cout << ans;
        return 0;
    }

    for (long long i = 0; i < (1 << n); i++){
        ans = (ans + calc(i)) % 998244353;
    }

    cout << ans;
    cout << endl;

    return 0;
}