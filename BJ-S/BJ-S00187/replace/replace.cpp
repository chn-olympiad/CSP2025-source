#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    cout << n / 2 << endl;
    for(int i = 0; i < q - 1; i ++){
        cout << i % 2 << endl;
    }
}
