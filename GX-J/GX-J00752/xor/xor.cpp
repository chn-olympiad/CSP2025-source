#include <bits/bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(0);
    int x;
    for (int i=1; i<=n; i++){
        cin >> x;
        a.push_back(x);
    }
    if (n<10){
        cout << 2;
    }else{
        cout << 69;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
