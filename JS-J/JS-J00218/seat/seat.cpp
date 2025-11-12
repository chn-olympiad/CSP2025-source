#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    int m,n,b,c=0,d=0,e=0,f=0;
    cin>>m>>n;
    for(int i=0;i<m*n;i++)
    {
        cin>>a[i];
    }
    c=a[0];
    for(int i=0;i<m*n;i++)
    {
        for(int j=i;j<m*n;j++)
        {
            if(a[i]<a[j])
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
        }
    }
    for(int i=0;i<m*n;i++)
    {
        if(c==a[i])
        {
            d=i+1;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(d>n*(i-1)&&d<=n*i)
        {
            e=i;
            f=d%n;
            if(f==0)
            {
                f=n;
            }
            if(i%2==0)
            {
                f=n+1-f;
            }
            break;
        }
    }
    cout<<e<<" "<<f;
    return 0;
}
