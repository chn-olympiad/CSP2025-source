#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,x[1000001]= {0};
    cin>>n>>m;
    for(int i=1; i<=m*n; i++)
    {
        cin>>x[i];
    }
    int xx=x[1],s;
    sort(x+1,x+1+m*n);
    for(int i=1; i<=n*m; i++)
    {
        if(x[i]==xx)
        {
            s=n*m-i+1;
            break;
        }
    }
    if(s%n==0)
    {
        cout<<s/n<<" ";
        if(s/n%2==0)
        {
            cout<<1;
        }
        else
        {
            cout<<n;
        }
    }
    else
    {
        cout<<s/n+1<<" ";
        if((s/n+1)%2==0)
        {
            cout<<n-s%n+1;
        }
        else
        {
            cout<<s%n;
        }
    }
    return 0;
}
