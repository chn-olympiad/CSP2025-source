#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[100010],a1 = 0,a0 = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        if (a[i] == 1){
            a1++;
        }else if (a[i] == 0){
            a0++;
        }
    }
    if (k == 0){
        cout << a0;
    }else if (k == 1){
        cout << a1;
    }
    return 0;
}

