#include <bits/stdc++.h>
using namespace std;
int n,m,s,a[105],A1,k;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    cin >> a[1];
    A1=a[1];
    for (int i = 2; i <= n*m;i+=1)
    {
        cin >> a[i];
    }
    sort(a + 1, a+1+n*m,cmp);
    for (int i = 1;i <= n*m;i++)
    {
        if (a[i] == A1)
        {
            s=i;
        }
    }
    k = s/n;
    if (s%n==0)
    {
        if (k%2==0)
        {
            cout << k << " " << 1;
        }
        else
        {
            cout << k << " " << n;
        }
    }
    else
    {
        if ((k+1)%2==0)
        {
            cout << k+1 << " " << n-(s%n)+1;
        }
        else
        {
            cout << k+1 << " " << s%n;
        }
    }
    return 0;
}
