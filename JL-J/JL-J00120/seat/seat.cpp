#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%lld",&a[i]);
    }
    int k=a[1];
    sort(a+1,a+1+n*m);
    int f=0;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]!=k)
        {
            f++;
        }
        else{
            break;
        }

    }
    int l;
    l=n*m-f;
    long long g;
    if(l/m==0)
    {
        cout<<1<<" ";
    }
    else
    {
        if(l==m)
        {
            cout<<1<<" ";
        }
        else
        {
            g=l/m+1;
            cout<<g<<" ";
        }

    }
    long long y;
    if((l/m)%2==1)
    {
        if(l%m==0)
        {
            cout<<m;
        }
        else
        {
            cout<<m-(l%m)+1;
        }
    }
    else
    {
        if(l%m==0)
        {
            cout<<1;
        }
        else
        {
            cout<<l%m;
        }
    }
    return 0;
}

