#include <bits/stdc++.h>
using namespace std;
int n,m,x,y=1;
int a[200];
int mapp[20][20];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(x==a[i])
        {
            x=i;
            break;
        }
    }
    while(x>n)
    {
        y++;
        x-=n;
    }
    cout << y << " ";
    if(y%2==0)
    {
        cout << n-x+1;
    }
    else
    {
        cout << x;
    }
    return 0;
}
