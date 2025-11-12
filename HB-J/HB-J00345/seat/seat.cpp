#include<bits/stdc++.h>
using namespace std;
int n,m,a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1],y=1;
    sort(a+1,a+1+n*m);
    for(int i=n*m;i>=1;i--)
    {
        if(a[i]==x)
        {
            break;
        }
        y++;
    }
    if(y%n==0)
    {
        if((y/n)%2==0)
        {
            cout<<y/n<<' '<<1;
        }
        else
        {
            cout<<y/n<<' '<<n;
        }
    }
    else
    {
        if((y/n+1)%2==0)
        {
            cout<<y/n+1<<' '<<n+1-y%n;
        }
        else
        {
            cout<<y/n+1<<' '<<y%n;
        }
    }
    return 0;
}
