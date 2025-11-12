#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N], t[N][N];
bool used[N];
int main(){
    freopen("xor.in","r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >>k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(i == j) t[i][j] = a[i];
            else{
                t[i][j] = a[i] ^ t[i-1][j];
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= N; i++){
        used[i] = false;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(t[j][i] == k && !used[i] && !used[j]){
                sum++;
                for(int ds = i; ds <= j; ds++){
                    used[ds] = true;
                }
            }
        }
    }
    cout << sum;
    return 0;
}
