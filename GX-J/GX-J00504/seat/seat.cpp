#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[105],n,m,i,j,rx,ry,z;
    cin>>n>>m;
    for(i=0;i<n*m;i++)
    {
        cin>>a[i];
        z=a[0];
    }
    for(i=0;i<n*m;i++)
    {
        for(j=i+1;j<n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }

    for(i=0;i<n*m;i++)
    {
        if(a[i]==z)
        {
            if((i+1)%m!=0)
            {
                rx=(i+1)/m+1;
            }
            else
            {
                rx=(i+1)/m;
            }
            if(rx%2==0)
            {
                ry=m-(i+1)%m+1;
            }
            else
            {
                if((i+1)%m==0)
                {
                    ry=m;
                }
                else
                {
                    ry=(i+1)%m;
                }
            }
        }
    }
    cout<<rx<<" "<<ry;
    return 0;
}
