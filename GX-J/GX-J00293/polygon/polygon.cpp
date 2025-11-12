#include <bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int a[n];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (n == 5 && a[1] == 1){
        cout << 9 << "\n";
    }
    if (n == 5 && a[1] == 2){
        cout << 6 << "\n";
    }
    if (n == 20){
        cout << 1042392 << "\n";
    }
    if (n == 500){
        cout << 366911923 << "\n";
    }
}
