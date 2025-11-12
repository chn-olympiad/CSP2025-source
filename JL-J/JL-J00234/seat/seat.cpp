#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110000],b,d;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n+1,a[n]);
    for(int i = 1;i<=n;i++)
    {
        if(a[i]==b)
        {
            d=i;
        }
    }
    int l=d/n+1;
    int h;
    if(l%2==0)
    {
        h=n-d%n;
    }
    else
    {
        h=d%n;
    }
    cout<<l<<" "<<h;
    return 0;
}
