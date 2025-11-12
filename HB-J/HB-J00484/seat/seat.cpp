#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s,l,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)cin>>a[i];
    s=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m; i>0; i--)
    {
        if(a[i]==s)
        {
            l=n*m-i+1;
            break;
        }
    }
    if(l%n!=0)
    {
        cout<<l/n+1<<" ";
        if((l/n+1)%2==1)cout<<l%n;
        else
        {
            cout<<n-(l%n)+1;
        }
    }
    else
    {
        cout<<l/n<<" ";
        if((l/n)%2==1)cout<<n;
        else
        {
            cout<<1;
        }



    }
    return 0;
}
