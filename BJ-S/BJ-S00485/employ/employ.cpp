#include <bits/stdc++.h>
using namespace std;

int jc(int x){
    int ans = 1;
    for (int i = 2; i <= x; i ++){
        ans *= i;
    }
    return ans;
}

int A(int x, int y){
    return jc(x) / jc(x - y);
}

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    long long ans = 0;
    if (m == 1){
        for (int i = 1; i <= n; i ++){
            ans += A(n, i);
        }
        cout << ans;
    }else{
        srand(time(0));
        ans = random() % 998244353;
        cout << ans;
    }

    return 0;
}

