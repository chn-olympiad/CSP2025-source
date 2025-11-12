#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","W",stdout);
    int n,m;
    cin >> n >> m;
    cin >> a[1];
    int last=a[1];
    for(int i=2;i<=n*m;i++)
        cin >> a[i];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1;
    if(a[1]==last)
    {
        cout << 1 << " " << 1 ;
        return 0;
    }
    for(int i=2;i<=n*m;i++)
    {

        if(y%2==1)
        {
            if(x!=n)
                x++;
            else
                y++;
        }
        else
        {
            if(x!=1)
                x--;
            else
                y++;
        }
        if(a[i]==last)
            cout << y << " " << x;

    }
    return 0;
}
