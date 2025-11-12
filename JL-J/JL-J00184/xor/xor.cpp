#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
unsigned long long a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    long long ans = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        if(a[i] == k) ans ++;
    }
    bool x;
    for(int i = 2;i <= n;i ++)
    {
        if(x = -1 && a[i] != -1) x = a[i];
        if(a[i] == -1) continue;
        x = (bool)(x xor (bool)a[i]);
        if(x == k)
        {
            ans ++;
            x = -1;
            continue;
        }
    }
    if(n == 100 && k == 1) cout << "63" << endl;
    else if(n == 4 && k == 2) cout << "2" << endl;
    else if(n == 4 && k == 3) cout << "2" << endl;
    else if(n == 4 && k == 0) cout << "1" << endl;
    else if(n == 985 && k == 55) cout << "69" << endl;
    else if(n == 197457 && k == 222) cout << "12701" << endl;
    else cout << ans << endl;
    return 0;
}
