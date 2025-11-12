#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,s,sum=1;
    int a[200];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            s=a[i];
        }
    }

    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>s)
        {
            sum++;
        }
    }

    s=sum;
    double l=s*1.0/n;
    int l2=ceil(l);
    int h;
    if(s%(2*n)<=n)
    {
        h=s%(2*n);
    }
    else{
        h=s%(2*n)-n;
        h=n-h+1;
    }
    cout<<l2<<' '<<h;
    return 0;
}
