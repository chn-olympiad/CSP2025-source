#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[10001];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int ans=a[1];
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]<a[i+1])swap(a[i],a[i+1]);
    }
    int x=1,y=1;
    for(int i=1;i<=n*m;i++)
    {
        if(ans!=a[i])
        {
            y++;
            if(y>m)
            {
                y=1;
                x++;
            }
        }
        else if(ans==a[i])
        {
            cout<<x<<" "<<y;
            return 0;
        }
    }
}
