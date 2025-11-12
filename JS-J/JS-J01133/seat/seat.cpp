#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n=0,m=0;
    cin>>n>>m;
    long long x=0,y=0,cnt=1,a=0,b=0;
    cin>>x;
    for(long long i=1;i<=n*m-1;i++)
    {
        cin>>y;
        if(y>x)cnt++;
    }
    if(cnt%n==0)
    {
        b=cnt/n;
        if(b%2==0)cout<<b<<" "<<"1";
        else cout<<b<<" "<<n;
        return 0;
    }
    else b=cnt/n+1;
    if(b%2==0)a=n-(cnt%n)+1;
    else a=cnt%n;
    cout<<b<<" "<<a;
    return 0;
}
