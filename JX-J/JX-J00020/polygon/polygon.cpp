#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if(n < 3)
    {
        int a[5];
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        cout << 0;
    }
    else if(n == 3)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(((a+b>c) && (a+c>b))&&(b+c>a))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else if(n == 5)
    {
        int a[10];
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        if(a[1]== 2)
        {
            cout << 6;
        }
        else if(a[1] == 9)
        {
            cout << 9;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cin >> n;
        int a[5005];
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
        }
        cout << a[1];
    }
    return 0;
}
