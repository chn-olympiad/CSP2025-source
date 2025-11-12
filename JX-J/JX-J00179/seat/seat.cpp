#include<bits/stdc++.h>
using namespace std;
int a[10001];
bool cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int x = a[1];
    sort(a+1,a+n*m+1,cmp);
    int xid;
    for(int i = 1;i<=n*m;i++)
    {
        if(a[i] == x)xid = i;
    }
    int xl = xid/n;
    xl++;
    int xh = xid%n;
    if(xh == 0)
    {
        xh+=n;
        xl--;
    }
    if(xl%2)
    {
        cout << xl << " " << xh << endl;
    }
    else
    {
        cout << xl << " " << n-xh+1 << endl;
    }
    return 0;
}
