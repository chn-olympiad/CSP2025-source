#include <bits/stdc++.h>
using namespace std;
int a[5002],b[5002],c[5002];
int main()
{
int n,cnt = 0;
cin >> n;
for(int i = 1; i <= n; i++)
{
    cin >> a[i];
}
for(int i = 1; i <= n; i++)
{
    for(int j = 1; j <= n; j++)
    {
        b[j]= max(b[j],b[j+1]);
        b[j+1] = min(b[j],b[j+1]);
    }
}
int x = 3;
while(x <= n)
{
    for(int i = 1; i <= n; i++)
    {
        c[i] = a[i];
    }
    y = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            b[j] = c[j];
            y += b[j];
        }
        if(y > b[x]*2)
        {
            cnt++:
        }
        for(int i = 1; i <= n; i++)
        {
            c[i] = c[i+1];
        }
    }
    x++;
}
cout << cnt;
return 0;
}
