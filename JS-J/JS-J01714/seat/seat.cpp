#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    int myr=0;
    int sum=n*m;
    int l=0;
    int h=0;
    sort(a+1,a+sum+1);
    for (int i=sum;i>=1;i--)
    {
        if (a[i]==r)
        {
            myr=sum-i+1;
        }
    }
    if (myr%n==0)
    {
        l=myr/n;
    }else
    {
        l=myr/n+1;
    }
    if (l%2==0)
    {
        if (myr%n==0)
        {
            h=1;
        }else
        {
            h=n-(myr%n)+1;
        }
    }else
    {
        if (myr%n==0)
        {
            h=n;
        }else
        {
            h=myr%n;
        }
    }
    cout<<l<<" "<<h;
    return 0;
}
