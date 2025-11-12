#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n,m,sum=1;
    cin >> n >>m;
    string a;
    cin >> a;
    for(int i = 1; i <= n;i++){
        int c;
        cin >> c;
        sum = sum*c%998244353;
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
