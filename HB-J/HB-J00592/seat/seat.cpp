#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],an,ma=1;
void ans(int x,int y)
{
    if(y>0)
    {
        if(x%2==0)
        {
            x++;
            cout<<x<<" "<<y;
            return ;
        }
        if(x%2==1)
        {
            x++;
            y=n-y+1;
            cout<<x<<" "<<y;
            return ;
        }
    }
    if(y==0)
    {
        if(x%2==0)
        {
            cout<<x<<" "<<1;
            return ;
        }
        if(x%2==1)
        {
            cout<<x<<" "<<n;
            return ;
        }
    }
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    an=a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>an)
        {
            ma++;
        }
    }
    int k=ma/n;
    int l=ma%n;
    ans(k,l);
    return 0;
}

