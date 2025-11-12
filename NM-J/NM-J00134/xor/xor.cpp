#include <bits/stdc++.h>
using namespace std;
int a[100001],c[100001];
int main()
{
int n,k,cnt = 0,x=1,y;
cin >> n >> k;
for(int i = 1; i <= n; i++)
{
    cin >> a[i];
}
for(int i = 1; i <= n; i++)
{
    if(a[i] == a[i+1])
    {
        c[i] = 0;
    }
    else
    {
        c[i] = 1;
    }
}
while(x <= n)
{
    for(int i = 1; i <= n; i++)
    {
        y = 0;
        for(int j = i; j <= x+i; j++)
        {
            y+=c[j];
        }
        if(y == k)
        {
            cnt++;
        }
    }
    x++;
}
cout << cnt;
return 0;
}
