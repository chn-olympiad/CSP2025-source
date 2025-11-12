#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[105],n,m,c,cx,cy;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    cy=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==cy)
        {
            c=i;
            break;
        }
    }
    if(c%n==0)
    {
        cx=c/n;
    }
    else
    {
        cx=c/n+1;
    }
    if(cx%2==1)
    {
        cout << cx << " " << cx*n-n*(c-1);
    }
    else
    {
        if(c-n*(cx-1)==1)
        {
            cout << cx << " " << n;
        }
        else
        {
            cout << cx << " " << n+1-(c-n*(cx-1));
        }
    }
    return 0;
}
