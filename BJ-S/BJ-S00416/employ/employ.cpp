#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >>m;
    string s;
    cin >> s;
    long long int w;
    for(int i = 0;i < s.size();i++)
    {
        int q = int(s[i]);
        w += q*(s.size()-i)*10;
    }
    cout << w % 998244353;
    return 0;
}
