#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,cnt = 0;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if(c[i] == 0) cnt++;
    }
    if(cnt >= n - m + 1)
    {
        cout << "0" << endl;
        return 0;
    }
    long long mul = 1;
    for(int i = 1; i <= n; i++)
    {
        mul = (mul * i) % mod;
    }
    cout << mul << endl;
    return 0;
}
