#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[0];
    for(int i=0;i<=n*m;i++)
    {
        for(int j=0;j<n*m-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int s=a[j];
                a[j]=a[j+1];
                a[j+1]=s;
            }
        }
    }
    int p;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==r)
        {
            p=i+1;
        }
    }
    int h,l;
    for(int i=1;i<=m;i++)
    {
        if(p>(i-1)*4&&p<=i*4)
        {
            l=i;
            break;
        }
    }
    if(l%2==1)
    {
        h=p-(l-1)*4;
    }
    else{
        h=l*4+1-p;
    }
    cout<<l<<" "<<h;
    return 0;
}
