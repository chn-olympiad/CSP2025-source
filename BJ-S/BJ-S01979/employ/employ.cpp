#include <iostream>
using namespace std;

const long long mod = 998244353;

long long a[505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m;
    cin >> n >>m;
    string s;
    cin >> s;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '0' && m == n)
        {
            cout << 0 << endl;
            exit(0);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == 0 && m == n)
        {
            cout << 0 << endl;
            exit(0);
        }
    }
    long long ans = 1;
    for(int i = 1;i <= n;i++)
    {
        ans = ans * i;
        ans %= mod;
    }
    cout << ans % mod << endl;
    return 0;
}
