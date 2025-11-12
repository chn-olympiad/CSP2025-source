#include <bits/stdc++.h>
using namespace std;
string s;
char m[1000005];
int idx;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= '0' && s[i] <= '9')
            m[++idx] = s[i];
    sort(m + 1,m + idx + 1,greater<int>());
    for (int i = 1; i <= idx; i++)
        cout << m[i];
    return 0;
}
