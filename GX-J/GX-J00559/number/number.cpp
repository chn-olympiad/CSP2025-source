#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    char a[10005];
    char b[10005];
    char c = 48;
    char y = 48;
    char num[105];
    cin >> a;
    for(int i = 0;i <= 105;i++)
    {
        for(int j = 0;j <= 9;j++)
        {
            if(a[i] == c)
            {
                b[i] = a[i];
            }
            c++;
        }
        c = 48;
    }

    for(int i = 0;i <= 105;i++)
    {
        if(b[i] > y)
        {
            y = b[i];
        }
    }
    num[0] = y;

    for(int i = 0;i <= 105;i++)
    {
        if(y > b[i])
        {
            y = b[i];
        }
    }
    num[1] = y;
    for(int i = 0;i <= 105;i++)
    {
        if(y > b[i])
        {
            y = b[i];
        }
    }
    num[2] = y;
    for(int i = 0;i <= 105;i++)
    {
        if(y > b[i])
        {
            y = b[i];
        }
    }
    num[3] = y;
    for(int i = 0;i <= 105;i++)
    {
        if(y > b[i])
        {
            y = b[i];
        }
    }
    num[4] = y;

    for(int i = 0;i <= 105;i++)
    {
        cout << num[i];
    }
    return 0;
}
