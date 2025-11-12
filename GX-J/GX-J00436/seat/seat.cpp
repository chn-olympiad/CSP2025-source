#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,s[15][15],c = 1;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >>m;
    for(int i = 1;i <= n*m+1;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++)
    {
        if(i %2 != 0)
        {
            for(int j = 1;j <= n;j++)
            {
                s[i][j] = c;
                c++;
            }
        }
        else
        {
            for(int j = n;j >= 1;j--)
            {
                s[i][j] = c;
                c++;
            }
        }
    }
    b= a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i <= n*m;i++)
    {
        if(a[i] == b)
        {
            b = i;
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(s[i][j] == b)
            {
                cout << i << " " <<j;
            }
        }
    }
    return 0;
}
