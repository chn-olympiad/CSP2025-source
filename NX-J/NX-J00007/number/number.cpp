#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cpp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char c;
    int s = 0;
    while(cin >> c)
    {
        if(c >= '0' && c <= '9')
        {
            a[s] = int(c-'0');
            s++;
        }
    }
    sort(a, a+s, cpp);
    for(int i = 0; i < s; i++)
    {
        cout << a[i];
    }
    return 0;
}
