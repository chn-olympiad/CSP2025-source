#include <bits/stdc++.h>
using namespace std;
long long n, q;
string s1[200005], s2[200005], q1, q2;
void f(int x)
{
    string n1 = s1[x], n2 = s2[x];
    int l = -1, r;
    for(int i = 0;i < n1.length();i ++)
    {
        if(n1[i] != n2[i])
        {
            r = i;
            if(l == -1) l = i;
        }
    }
    n1 = n1.substr(l, r - l + 1);
    n2 = n2.substr(l, r - l + 1);
    s1[x] = n1;
    s2[x] = n2;
}

void g()
{
    if(s1[n].length() != s2[n].length())
    {
        cout << "0\n";
        return;
    }
    int ans = 0;
    f(n);
    for(int i = 0;i < n;i ++)
    {
        if(s1[n] == s1[i] && s2[n] == s2[i]) ans ++;
    }
    cout << ans << '\n';
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 0;i < n;i ++)
    {
        cin >> s1[i] >> s2[i];
        f(i);
    }
    while(q --)
    {
        cin >> s1[n] >> s2[n];
        g();
    }
    return 0;
}