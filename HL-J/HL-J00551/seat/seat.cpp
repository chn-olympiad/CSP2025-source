#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a1,n,m,j=0,c=1,r=1;
    cin>>n>>m;
    int a[n*m];
    cin>>a1;
    a1=a[0];
    for(int i=1;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n*m;i++)
    {
        for(int j=0;j<n*m-1;j++)
        {
            if(a[j+1]>a[j])
            {
                int m;
                a[j+1]=m;
                a[j+1]=a[j];
                a[j]=m;
            }
        }
    }
    while(a[j]!=a1)
    {
        if(c%2==1)
        {
            if(r==n)
            {
                c++;
                j++;
            }
            else
            {
                r++;
                j++;
            }
        }
        else
        {
            if(r==1)
            {
                c++;
                j++;
            }
            else
            {
                r--;
                j++;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
