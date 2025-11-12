#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[102],mc=1;
    cin>>a[1];
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1]) mc+=1;
    }
    int l,h;
    if(mc%n==0)
    {
        l=mc/n;
        if(l%2==0) h=1;
        else h=n;
    }
    else
    {
        l=mc/n+1;
        if(l%2!=0)
        {
            h=mc%n;
        }
        else
        {
            h=n-(mc%n)+1;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
