#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);

    int n,m,cj=0,xb=0,x=0,y=0;
    cin>>n>>m;
    int a[n*m],b[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    cj=a[0];
    sort(b,b+n*m,greater<int>());
    for(int i=0;i<n*m;i++)
    {
        if(b[i]==cj)
            xb=i+1;
    }
    if(xb%n<n)
        y=1;
    else if(xb%n>n)
        y=xb/n+1;
    cout<<y;
    return 0;
}
