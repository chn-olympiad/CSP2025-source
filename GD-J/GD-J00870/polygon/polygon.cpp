#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
vector<int> a;
int n;

void doit(int depth, int start, long long id, int orig){
    if(depth == 0){
        if(a[orig] < id){
            ans++;
        }
        return;
    }
    else{
        for(int i = start; i < n; i++){
            cout << a[i] << endl;
            doit(depth - 1, i + 1, id + a[i], orig);
        }
    }
    return;
}

int main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    if(n <= 3){
        if(n != 3){
            cout << 0 << endl;
            return 0;
        }
        if(n == 3){
            if(a[0] < a[1] + a[2]){
                cout << 1 << endl;
                return 0;
            }
            cout << 0 << endl;
            return 0;
        }
    }
    if(n <= 10){
        if(n == 4){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 5){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 6){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o]){
                                        ans = (ans + 1) % 998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 7){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o]){
                                        ans = (ans + 1) % 998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p]){
                                            ans = (ans + 1) % 998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 8){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o]){
                                        ans = (ans + 1) % 998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p]){
                                            ans = (ans + 1) % 998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q]){
                                                ans = (ans + 1) % 998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 9){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o]){
                                        ans = (ans + 1) % 998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p]){
                                            ans = (ans + 1) % 998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q]){
                                                ans = (ans + 1) % 998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            for(int r = q + 1; r < n; r++){
                                                if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r]){
                                                    ans = (ans + 1) % 998244353;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
        if(n == 10){
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        if(a[i] < a[j] + a[k]){
                            ans++;
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            if(a[i] < a[j] + a[k] + a[l]){
                                ans++;
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                if(a[i] < a[j] + a[k] + a[l] + a[m]){
                                    ans = (ans + 1) % 998244353;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o]){
                                        ans = (ans + 1) % 998244353;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p]){
                                            ans = (ans + 1) % 998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q]){
                                                ans = (ans + 1) % 998244353;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            for(int r = q + 1; r < n; r++){
                                                if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r]){
                                                    ans = (ans + 1) % 998244353;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    for(int k = j + 1; k < n; k++){
                        for(int l = k + 1; l < n; l++){
                            for(int m = l + 1; m < n; m++){
                                for(int o = m + 1; o < n; o++){
                                    for(int p = o + 1; p < n; p++){
                                        for(int q = p + 1; q < n; q++){
                                            for(int r = q + 1; r < n; r++){
                                                for(int s = r + 1; s < n; s++){
                                                    if(a[i] < a[j] + a[k] + a[l] + a[m] + a[o] + a[p] + a[q] + a[r] + a[s]){
                                                        ans = (ans + 1) % 998244353;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout << ans << endl;
            return 0;
        }
    }
    for(int j = 3; j < n; j++){
        for(int i = 0; i < n; i++){
            doit(j, i + 1, 0LL, i);
            ans = ans % 998244353;
        }
    }
    cout << ans << endl;
    return 0;
}