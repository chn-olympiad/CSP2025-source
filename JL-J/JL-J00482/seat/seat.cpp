#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[105],c=1,r=1;
    cin>>n>>m;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=n*m;i++)
    {
        if(a[0]==max(a[0],a[n*m]))
        {
            c=1;
            r=1;
        }
        if(a[0]>=a[i])
        {
            break;
        }
        if(a[0]<a[i])
        {

            if(c%2==0)
            {
                if(r-1==0)
                    c++;
                    break;
                r--;
            }
            else if(r==n)
                c++;
            else
                r++;



        }
        if(a[0]==a[i])
        {
            break;
        }

    }
    cout<<c<<" "<<r;
    return 0;
}
