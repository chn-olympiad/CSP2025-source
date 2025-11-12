#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],z,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    z=a[1];
    sort(a+1,a+n*m+1);
    x=1;
    for(int i=n*m;i>=1;i--)
    {
        if(x&1)y++;
        else y--;
        if(y>n||y==0)
        {
            x++;
            if(x&1)y=1;
            else y=n;
        }
        if(a[i]==z)
        {
            cout<<x<<" "<<y;
            return 0;
        }
    }
}