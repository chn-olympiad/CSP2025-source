#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],s=0,x=1,y=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
        {
            s++;
        }
    }
    s++;
    if(s<=n)
    {
        x=1;
        y=s;
        cout<<x<<" "<<y;
        return 0;
    }
    else if(s/n>1&&s%n!=0&&s/(s/n+1)%2!=0)
    {
        x=s/n+1;
        y=s%n;
        cout<<x<<" "<<y;
        return 0;
    }
    else
    {
        x=s/n+1;
        y=n-s%n+1;
        cout<<x<<" "<<y;
        return 0;
    }
    return 0;
}
