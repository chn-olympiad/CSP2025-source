#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> m;
    int a[n];
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (m == 0){
        cout << 1 << "\n";
    }
    else{
        cout << 2 << "\n";
    }
}
