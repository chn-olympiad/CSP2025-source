#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod = 998244353;
int a[5005];
signed main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    int n;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >>a[i];
    int ans = 0;
	if(a[1] + a[2] + a[3] > 2 * (max(a[1] , max(a[2] , a[3]))))ans++;
    cout << ans;
}
