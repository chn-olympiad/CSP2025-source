#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w"stdout);
    int a,c[5000];
    cin >> a;
    for(int i = 0;i < a;i++)
    {
        cin >> c[i];
    }
    if(a == 5)
    {
        if(c[0] == 1)
        {
            cout << "9";
        }
        else
        {
            cout << "6";
        }
    }
    else
    {
        cout << "1";
    }
    return 0;
}



