#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string a = "";
    for(LL i = 0;i < s.size();i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a += s[i];
        }
    }
    sort(a.rbegin(),a.rend());
    for(LL i = 0;i < a.size();i++)
    {
        cout << a[i];
    }
    return 0;
}
//I AK CSP-J 2025!
