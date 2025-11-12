#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],RR,r;
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
    RR = a[1];
    for (int i = 2;i < n*m;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for (int i = 1;i <= n*m;i++)
    {
        if (a[i] == RR)
            r = i;
    }
    if ((r/n)%2 == 1 && r%n == 0)
    {
        cout << r/n << " " << n; 
    }
    else if ((r/n)%2 == 0 && r%n == 0)
        cout << r/n << " " << 1;
    else if ((r/n+1)%2 == 1 && r%n != 0)
    {
        cout << r/n << " " << r%n; 
    }
    else if ((r/n+1)%2 == 0 && r%n != 0)
        cout << r/n << " " << n-r%n+1;
    return 0;
}
