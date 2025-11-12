#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int n, q;
map<string, int> mp;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    string s1, s2;
    cin >> n >> q;
    for (int i = 1;i <= n;i ++)
    {
        cin >> s1 >> s2;
        s1 = s1 + '#' + s2;
        mp[s1] ++;
    }


    int ans;
    for (int i = 1;i <= q;i ++)
    {
        ans = 0;
        cin >> s1 >> s2;
        int len1 = s1.length(), len2 = s2.length();
        int len = min(len1, len2);
        int l = 0, r = 0;
        while (l < len && s1[l] == s2[l])
            l ++;
        while (r < len && s1[len1 - r - 1] == s2[len2 - r - 1])
            r ++;

        string s;
        for (int i = 0;i <= l;i ++)
            for (int j = 0;j <= r;j ++)
            {
                s = s1.substr(i, len1 - j - i) + '#' + s2.substr(i, len2 - j - i);
                if (mp.find(s) != mp.end())
                    ans += mp[s];
            }

        cout << ans << '\n';
    }
    return 0;
}
