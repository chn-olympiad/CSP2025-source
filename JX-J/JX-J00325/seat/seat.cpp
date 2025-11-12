#include<bits/stdc++.h>
using namespace std;
long long n,m,a[150],xhm,cnt=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    cin>>n>>m;
    cin>>xhm;
    for(int i=1;i<=n*m-1;i++)
    {
        cin>>a[i];
        if(a[i]>xhm) cnt++;
    }
    int seatx=ceil(cnt*1.0/n);
    if(seatx%2==1)
    {
        cout<<seatx<<' ';
        if(cnt%n==0) cout<<n;
        else cout<<cnt%n;
    }
    else if(seatx%2==0)
    {
        cout<<seatx<<' ';
        if(cnt%n==0) cout<<1;
        else cout<<n-cnt%n+1;
    }
    return 0;
}
