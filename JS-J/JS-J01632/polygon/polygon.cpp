#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    if(n < 3 or n > 3){
    cout << 0 << '\n';
    return 0;
    }
    sort(a + 1,a + 1 + n,greater<int>());
    if(a[1] + a[2] + a[3] > 2 * a[1])
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}
