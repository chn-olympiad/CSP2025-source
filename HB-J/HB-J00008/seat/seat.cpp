#include<bits/stdc++.h>
using namespace std;
int a[101]={0};
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b,e=0,c=0,r=0,d=0,f=0;
    cin>>n>>m;
    b=n*m;
    for(int i=1;i<=b;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            e=a[i];
        }
    }
    for(int y=1;y<b;y++)
    {
        for(int j=1;j<b;j++)
        {
            if(a[j]>a[j+1])
            {
                f=a[j];
                a[j]=a[j+1];
                a[j+1]=f;
            }

        }
    }


    for(int i=b;i>=1;i--)
    {
        if(a[i]==e)
        {
            d=b-i+1;
        }
    }
    if((d/n%2==1 && d%n==0)||(d/n%2==0 && d%n==1))
    {
        r=d%n;
        if(r==0)
        {
            r=n;
        }
    }

    else
    {
        r=n-(d%n)+1;
    }
    c=d/n;
    if(d%n>0)
    {
        c=c+1;
    }
    cout<<c<<' '<<r<<endl;
    return 0;

}
