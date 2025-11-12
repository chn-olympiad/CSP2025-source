#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,f,a[1003];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    z=a[1];
    sort(a+1,a+n*m+1,cmp);
    x=1,y=1,f=1;
    if(a[1]==z)
    {
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=2;i<=n*m;i++)
    {
        if(f) y++;
        else y--;
        if(y>m)
        {
            x++;
            y--;
            f=0;
        }
        else if(y<1)
        {
            y++;
            x++;
            f=1;
        }
        if(a[i]==z)
        {
            cout<<x<<" "<<y;
            return 0;
        }
    }
    return 0;
}
