#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int a[N];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int ai=0;
    for(int i=1;i<=n*m;i++)
    {
       cin>>a[i];
       if(i==1)
       {
           ai=a[i];
       }
    }
    sort(a+1,a+1+n*m,cmp);
    int l=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ai)
        {
           l=i;
           break;
        }
    }
    int f=ceil(l*1.0/n);
    cout<<f<<' ';
    if(f%2!=0)
    {
       int k=l%n;
       if(k==0)
       {
          cout<<n;
       }
       else{cout<<k;}
    }
    else
    {
        int k=l%n;
        if(k==0)
        {
            cout<<1;
        }
        else
        {
            cout<<k+1;
        }
    }
    return 0;
}
