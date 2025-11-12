#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[114];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int cn=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])cn++;
    }
    int c;int r;
    if((cn+1)%n==0)
    c=(cn+1)/n;
    else
    c=(cn+1)/n+1;
    
    if(c%2==1)
    {
        r=(cn+1)%n;
        if(r==0)r=n;
    }
    if(c%2==0)
    {
        r=n-((cn+1)%n);
        if(r==n)r=1;
        else r++;
    }
    cout<<c<<" "<<r;
    return 0;
}