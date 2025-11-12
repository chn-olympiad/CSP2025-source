#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int n1 = n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x == 0) n1--;
    }
    ll sum = 1;
    for(int i = 2;i <= n1;i++) sum = (sum * i) % MOD;
    cout << sum % MOD;
    return 0;
}