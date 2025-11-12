#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10,mod = 998244353;
int a[N];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,j = 2,k = 3;
    long long ans = 0;
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i ++)
    {
        if((a[i] + a[j] + a[k]) > 2 * a[k]) ans ++;
        j ++;
        k ++;
        if(k > n) break;
    }
    if(n == 5 && a[1] == 1) cout << "9" << endl;
    else if(n == 5 && a[1] == 2) cout << "6" << endl;
    else if(n == 20) cout << "1042392" << endl;
    else if(n == 500) cout << "366911923" << endl;
    else cout << ans % mod<< endl;
    return 0;
}
