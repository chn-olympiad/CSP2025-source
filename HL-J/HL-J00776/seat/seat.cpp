#include <bits/stdc++.h>

using namespace std;

int a[100*100]={0};

int main()
{
    int n=0;
    int m=0;
    int AL=0;
    int a1=0;
    int c=0;
    int r=0;
    int al=0;

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;

    for(int i=0;i<n*m;i++)
        cin>>a[i];

    for(int i=1;i<n*m;i++)
        if(a[0]<a[i])
           a1++;

        al=a1;

    if(a1%n==0)
       c=a1/n;
    else
       c=a1/n+1;

    if(c%2==1)
       r=n-(c*n-al);
    else
       r=c*n-al+1;

    cout<<c<<' '<<r<<endl;

    return 0;
}
