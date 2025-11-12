#include<bits/stdc++.h>
using namespace std;
long long pos1=1,n,m,al=0,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cin>>al;
    for(long long i=2;i<=n*m;i++)
    {
        long long x;
        cin>>x;if(x>al)pos1++;
    }
    if(pos1%n==0)
    {
        x=pos1/n;
        if(x%2==1)y=n;
        else y=1;
    }
    else
    {
        x=pos1/n+1;
        if(x%2==1)y=pos1%n;
        else y=n+1-pos1%n;
    }
    cout<<x<<" "<<y;
    return 0;
}
