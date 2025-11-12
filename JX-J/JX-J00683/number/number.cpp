#include <bits/stdc++.h>
using namespace std;
char n[1000000];
string a;

bool cmp(char x , char y)
{
    return x > y;
}

int main()
{
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> a;
    int m = a.length();
    for (int i = 0;i < m;i++)
    {
        if (a[i] <= '9' && a[i] >= '0')
        {
            n[i] = a[i];
        }
    }
    sort(n , n + m , cmp);
    for (int i = 0;i < 1000000;i++)
    {
        if(n[i] != 0)
        {
            cout << n[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
