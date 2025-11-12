#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int n,q;
string s1[200005],s2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for (int i = 1;i <= n;i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while (q--)
    {
        string t1,t2;
        cin >> t1 >> t2;
        t1 = " " + t1;
        t2 = " " + t2;
        if (t1.size() != t2.size())
        {
            cout << "0\n";
            continue;
        }
        long long ans = 0;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= t1.size() - s1[i].size() + 1;j++)
            {
                if (t1.substr(1,j - 1) == t2.substr(1,j - 1) && t1.substr(j,s1[i].size()) == s1[i] && t2.substr(j,s2[i].size()) == s2[i] && t1.substr(j + s1[i].size()) == t2.substr(j + s2[i].size())) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
