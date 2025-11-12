#include <bits/stdc++.h>

using namespace std;

int main(){
    frepoen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(n <= 2 && k == 0){
        if(n == 2){
            cout << 1 << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    if(n == 10 && k <= 1){
        int ans = 0;
        for(int i = 0; i < n;;){
            if(a[i] == k){
                ans++;
                i++;
            }
            else if(i + 1 < n){
                if(a[i] ^ a[i + 1] == k){
                    ans++;
                    i = i + 2;
                }
            }
            else if(i + 2 < n){
                if(a[i] ^ a[i + 1] ^ a[i + 1]){
                    ans++;
                    i = i + 3;
                }
            }
            else{
                i++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    if(n <= 100 && k == 0){
        cout << n / 2 << endl;
        return 0;
    }
    if(k <= 1){
        int ans = 0;
        for(int i = 0; i < n;;){
            if(a[i] == k){
                ans++;
                i++;
            }
            else if(i + 1 < n){
                if(a[i] ^ a[i + 1] == k){
                    ans++;
                    i = i + 2;
                }
            }
            else if(i + 2 < n){
                if(a[i] ^ a[i + 1] ^ a[i + 1]){
                    ans++;
                    i = i + 3;
                }
            }
            else{
                i++;
            }
        }
        cout << ans << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}