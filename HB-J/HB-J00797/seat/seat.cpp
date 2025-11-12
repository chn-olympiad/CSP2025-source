#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int z=n*m;
    int a[105]={};
    int x=0,y=0;
    for(int i=1;i<=z;i++)
    {
        cin>>a[i];
    }
    int flag=a[1];
    sort(a+1,a+z+1,cmp);
    for(int i=1;i<=z;i++)
    {
        if(flag==a[i])
            {
                if(i%n==0)
                    x=i/n;
                else
                    x=i/n+1;
                if(x%2!=0 && i!=n)
                    y=i%n;
                else if(x%2!=0 && i==n)
                    y=n;
                else
                    y=(x*n)-i+1;
            }
    }

    cout<<x<<" "<<y;
    return 0;
}
