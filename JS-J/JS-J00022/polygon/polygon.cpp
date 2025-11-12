#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5005;
ll n;
ll num[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> num[i];
    }
    ll ans = n - 2 + (n - 1) * (n - 1);
    cout << ans <<endl;
    return 0;
}
