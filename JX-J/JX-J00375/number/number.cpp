#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int r[1000005];
    cin >> a;
    for (int i = 0;i < a.size();i++)
    {
        r[i] = a[i];
    }
    sort(r,r + a.size() + 1);
    for (int i = a.size() - 1;i = 0;i--)
    {
        cout << r[i];
    }
    return 0;
}
