#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,i,x=1,l=1,as,st=0,k=0,sd,sf;
    cin>>n>>m;
    int a[n*m];
    for(i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    as=a[0];
    sort(a,a+n*m);
    for(i=n*m-1;i>=0;i--)
    {
        st++;
        if(a[i]==as)
        {
            break;
        }
    }
    l=st/m;
    if(st%m!=0)
    {
       l++;
    }
    if(l%2!=0) x=st%n;
    else
    {
        x=st%n;
        x=n-x+1;
    }
    if(x==0) x=n;
    cout<<l<<" "<<x;
    return 0;
}

