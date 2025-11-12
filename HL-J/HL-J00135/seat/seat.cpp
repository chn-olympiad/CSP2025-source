#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n,m;
long long a[100005];
long long r;

bool cmp(long long x,long long y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];

    sort(a+1,a+n*m+1,cmp);

    long long id;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            id=i;
        }
    }

    long long x=id/n,y=id%n,h,l;
    //列数
    if(y==0)
        l=x;
    else
        l=x+1;

    cout<<l<<' ';
    //行数
    if(l%2==1)
    {
        if(y==0)
            cout<<n;
        else
            cout<<y;
    }
    else
    {
        if(y==0)
            cout<<1;
        else
            cout<<n-y+1;
    }
    return 0;
}
