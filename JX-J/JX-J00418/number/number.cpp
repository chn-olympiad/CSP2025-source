#include <bits/stdc++.h>
using namespace std;
string d;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int max = 0,f = 0;
    vector <char> s;
    vector <int> a;
    vector <int> b;
    cin >> d;
    for(int i = 0;i < d.size();i++)
    {
        s.push_back(d[i]);
    }
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] = '1')
            a.push_back(int(s[i]));
        else if(s[i] = '2')
            a.push_back(int(s[i]));
        else if(s[i] = '3')
            a.push_back(int(s[i]));
        else if(s[i] = '4')
            a.push_back(int(s[i]));
        else if(s[i] = '5')
            a.push_back(int(s[i]));
        else if(s[i] = '6')
            a.push_back(int(s[i]));
        else if(s[i] = '7')
            a.push_back(int(s[i]));
        else if(s[i] = '8')
            a.push_back(int(s[i]));
        else if(s[i] = '9')
            a.push_back(int(s[i]));
        else if(s[i] = '0')
            a.push_back(int(s[i]));
    }
    for(int i = 0;i < a.size();i++)
    {
        max = 0;
        f = 0;
        for(int j = 0;j < a.size();j++)
        {
            if(int(a[j]) > max)
            {
                max = a[j];
                f = j;
            }
        }
        cout << max;
        a[f] = -1;
    }

    return 0;
}
