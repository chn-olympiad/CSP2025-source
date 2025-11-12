#include <bits/stdc++.h>
using namespace std;
int s,num,ans,a[15];
int wei(int x)
{
    while(x>0)
    {
        a[x%10]++;
        x = x/10;
    }
}
int main()
{
    freopen('number.in','r',stdin);
    freopen('number.out','w',stdout);
    cin >> s;
    wei(s);
    for (int i = 9;i >= 0; i--)
    {
        for (int j = a[i];j > 0;j--)
        {
            cout << i;
        }
    }
}
