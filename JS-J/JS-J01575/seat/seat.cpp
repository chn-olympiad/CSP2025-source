#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[110],a1,c=1,r,x=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    t=m*n;
    for(int i=1;i<=t;i++)
        cin>>a[i];
    a1=a[1];
    sort(a+1,a+t+1);
    for(int i=t;i>=1;i--)
    {
        r+=x;
        if(r==n+1)
        {
            r=n;
            x=-1;
            c++;
        }
        if(r==0)
        {
            r=1;
            x=1;
            c++;
        }
        if(a[i]==a1)
        {
            cout<<c<<" "<<r;
            return 0;
        }
    }
    return 0;
}
