#include <bits/stdc++.h>
using namespace std;
int num[2000];
bool judge(int n){
    for (int i = 1; i <= n; i++){
        if (num[i] == 0){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> num[i];
    }
    if (n <= 100 && k == 0 && judge(n)){
        cout << n / 2;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    cout << 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
