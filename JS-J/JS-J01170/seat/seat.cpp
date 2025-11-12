#include <bits/stdc++.h>
using namespace std;
long long n,m,a[110],sum=1;;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>a[1])
        {
            sum++;
        }
    }
    if(sum%n==0)
    {
        if((sum/n)%2==1)
        {
            cout<<sum/n<<" "<<n;
        }
        else
        {
            cout<<sum/n<<" "<<1;
        }
    }
    else
    {
        if((sum/n+1)%2==1)
        {
            cout<<sum/n+1<<" "<<sum%n;
        }
        else
        {
            cout<<sum/n+1<<" "<<n-(sum%n)+1;
        }

    }
    return 0;
}
