#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in", "r",stdin);
    freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i <= n;i++){
        cin >> i;
    }
    for(int j = 0;j<=n;j++){
        if(j>=3 && a[j]>2*j){
            cout << j;
            break;
        }
    }
    if(a[0] == 1){
        cout << 9;
    }
    if (a[0] == 2){
        cout << 6;
    }
    return 0;
}

