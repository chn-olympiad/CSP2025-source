#include<iostream>
using namespace std;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        ans *= i;
        ans %= 998244353;
    }
    cout << ans;
    return 0;
}
