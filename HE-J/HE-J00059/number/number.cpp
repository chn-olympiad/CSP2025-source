#include <bits/stdc++.h>
using namespace std;

int h[15];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin >> s;

    int n = s.size();
    s = " " + s;
    for(int i = 1;i <= n;i++)
    {
        if(isdigit(s[i]))
        {
            h[s[i]-'0']++;
        }
    }

    for(int i = 9;i >= 0;i--)
    {
        for(int j = 1;j <= h[i];j++)
        {
            printf("%d",i);
        }
    }

    return 0;
}
