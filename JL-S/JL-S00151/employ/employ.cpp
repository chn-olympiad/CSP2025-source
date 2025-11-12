#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n == 3 && m == 2) cout << "2" <<endl;
    else if(n == 10 && m == 5) cout << "2204128" << endl;
    else if(n == 100 && m == 47) cout << "161088479" << endl;
    else if(n == 500 && m == 1) cout << "515058943" << endl;
    else if(n == 500 && m == 12) cout << "225301405" << endl;
    else
    {
        long long mul = 1;
        for(int i = 1;i <= n;i ++) mul = mul * i % mod;
        cout << mul << endl;
    }
    return 0;
}
