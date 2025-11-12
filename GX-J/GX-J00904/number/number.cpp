#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number4.in", "r", stdin);
    freopen("number4.out", "w", stdout);
    string s;
    cin >> s;
    char t;
    for (int i = 0; i <= s.size()-1; i++)
    {
        for (int j = 0; j <= s.size()-1; j++)
        {
            if (s[i] > s[j])
            {
                t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    for (int i = 0; i <= s.size() - 1; i++)
    {
        cout << s[i] << endl;
    }
    return 0;
    

  
}
