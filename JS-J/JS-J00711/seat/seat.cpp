#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,d;
int cj,k,j;
const int N=1e3;
int a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    d=n*m;
    for(int i=1;i<=d;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            cj=a[i];
        }
    }
    sort(a+1,a+1+d);
    for(int i=1;i<=d;i++)
    {
        if(a[i]==cj)
        {
            cj=d-i+1;
            break;
        }
    }
    k=ceil(cj*1.0/n);
    j=cj%n;
    c=k;
    if(k%2==0)
    {
        r=n-j+1;
    }
    else if(k%2!=0)
    {
        if(j==0)
        {
            r=n;
        }
        else r=j;
    }
    cout<<c<<' '<<r;
    return 0;
}
