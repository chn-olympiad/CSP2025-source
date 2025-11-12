#include <bits/stdc++.h>
using namespace std;

string s1[10005], s2[100005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    if (q<=1000)
    {
        for (int i =1;  i<= n; i++)
        {
            cin >> s1[i] >> s2[i]; 
        }
        while (q--)
        {
            int sum = 0;
            string a, b;
            cin >> a >> b;
            for (int i = 1; i <= n; i++)
            {
                if (int(a.find(s1[i])) <= a.size())
                {
                    string x = "",y = "",z = "";
                    for (int j = 0; j < int(a.find(s1[i])); j++)
                    {
                        x = x + a[j];
                    }
                    y = s2[i];
                    for (int j = int(a.find(s1[i])) + int(s1[i].size()); j <= a.size(); j++)
                    {
                        z = z + a[j];
                    }
                    string tmp = x + y + z;
                    if (tmp == b)
                    {
                        sum++;
                    }
                }
            }
            cout << sum << endl;
        }
        return 0;
    }
    while (q--)
    {
        cout << 0 << endl;
    }
    return 0;
}
