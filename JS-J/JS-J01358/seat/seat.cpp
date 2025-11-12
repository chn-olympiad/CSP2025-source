#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[110],t,c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,greater<ll>());
    bool f=0;
    for(int i=1;i<=m;i++)
    {
        if(f==1)
        {
            break;
        }
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(t==a[(i-1)*n+j])
                {
                    c=i,r=j;
                    f=1;
                    break;
                }
            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                if(t==a[(i-1)*n+n-j+1])
                {
                    c=i,r=j;
                    f=1;
                    break;
                }
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
