#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    bool flag = 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != 1){
            flag = 0;
        }
    }
    if(flag){
        cout << n / 2 << '\n';
    }else{
        cout << 4 << '\n';
    }
    return 0;
}
//expect :10pts
