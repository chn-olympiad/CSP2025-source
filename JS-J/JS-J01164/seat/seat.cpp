#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[1001],num,ph,hs,ls;
int main()
{
   freopen("seat.in","r",stdin);
   freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(num==a[i])ph=n*m-i+1;
    }
    if(ph%n==0)ls=ph/n;
    else ls=ph/n+1;
    if(ph%n==0)
    {
        if(ls%2==1) hs=n;
        else hs=1;
    }
    else
        {
         if(ls%2==1)hs=ph%n;
    else hs=n-ph%n+1;
    }
    cout<<ls<<" "<<hs;
}
