#include<bits/stdc++.h>
using namespace std;
const int N = 5e5;
int n, k, cnt;
int a[N + 5];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    if(k == 0){
        for(int i = 1; i <= n; i ++){
            if(a[i] == 0)   cnt ++;
        }
        cout << cnt << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}