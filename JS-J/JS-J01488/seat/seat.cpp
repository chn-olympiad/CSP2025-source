#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105],r,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            s=n*m+1-i;
            break;
        }
    }
    int ansn,ansm;
    ansm=((s-1)/n)+1;
    if(s%(2*n)<=n&&s%(2*n)!=0)
    {
        ansn=s%(2*n);
    }
    else
    {
        if(s%(2*n)==0)
        {
            ansn=1;
        }
        else
        {
            ansn=2*n+1-(s%(2*n));
        }
    }
    cout<<ansm<<" "<<ansn;
    return 0;
}
