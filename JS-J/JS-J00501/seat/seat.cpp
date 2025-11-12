#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=m*n;i++)
    {
        cin >> a[i];
    }
    int t=0;
    int a1=a[1];
    sort(a+1,a+1+n*m);
    for (int i=n*m;i>=1;i--)
    {
        t++;
        if (a[i]==a1)
        {
            a1=t;
            break;
        }
    }
    if (a1%n==0)
    {
        cout<<a1/n << " ";
        if ((a1/n)%2==0)
        {
            cout << 1;
            return 0;
        }
        else
        {
            cout << n;
            return 0;
        }
    }
    cout << a1/n+1 << " ";
    int q=a1/n+1;
    a1=a1%n;
    if (q%2!=0)
    {
        cout << a1;
        return 0;
    }
    cout << n-a1+1;
    return 0;
}
