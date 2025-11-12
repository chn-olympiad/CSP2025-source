#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int a[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i ++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            a[(int)s[i] - 48] ++;
        }
    }
    bool flag = 0;
    for(int i = 9;i >= 0;i --)
    {
        for(int j = 1;j <= a[i];j ++)
        {
            if(flag == false && i == 0)
            {
                cout << "0";
                return 0;
            }
            cout << i;
            flag = true;
        }
    }
    return 0;
}
