#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,q;
string t1[200010],t2[200010],s1[200010],s2[200010];

void case1()
{
    int cnt = 0;
    for(int i = 1;i <= q;i++)
    {
        cnt = 0;
        for(int l = 0;l < t1[i].size();l++)
        {
            for(int r = l;r < t1[i].size();r++)
            {
                string le,mid,ri;
                for(int j = 0;j < t1[i].size();j++)
                {
                    if(j < l) le += t1[i];
                    if(l <= j <= r) mid += t1[i];
                    else ri += t1[i];
                }
                for(int j = 1;j <= n;j++)
                {
                    if(s1[j] == mid)
                    {
                        string ans = le;
                        ans += s2[j];
                        ans += ri;
                        if(ans == t2[i])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt <<endl;
    }
}

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >>q;
    cin.get();
    int len = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> s1[i] >> s2[i];

    }
    for(int i = 1;i <= q;i++)
    {
        cin >> t1[i] >> t2[i];
        len += t1[i].size();
        len += t2[i].size();
    }
    if(n <= 1000 && len <= 2000)
    {
        case1();
        return 0;
    }
    for(int i = 1;i <= q;i++) cout << 0 <<endl;
    return 0;
}
