#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a,k[1000000],h,b,p,o,g,t;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++)
    {
        cin>>a;
        if(i==1)
        {
            b=a;
        }
        k[i]=a;
        h=i;
    }
    sort(k,k+h+1);
    for(int i=1;i<=h;i++)
    {
        if(k[i]==b)
        {
            p=m*n+1-i;
        }
    }
    if(p%n==0)
    {
        o=p/n;
        if(o%2==0)
        {
            g=1;
        }
        if(o%2!=0)
        {
            g=n;
        }
    }
    if(p%n!=0)
    {
        o=p/n+1;
        t=p-(o-1)*n;
        if(o%2==0)
        {
            g=n+1-t;
        }
        if(o%2!=0)
        {
            g=t;
        }
    }
    cout<<o<<" "<<g;
    return 0;
}
