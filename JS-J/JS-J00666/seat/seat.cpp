#include<bits/stdc++.h>
using namespace std;
int n,m,s[101],a,l,x,y;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>s[i];
    }
    a=s[1];
    sort(s+1,s+n*m+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a==s[i])
        {
            l=n*m-i+1;
        }
    }
    x=l/n+1;
    if(x%2==1)
    {
        y=l%n;
        if(y==0)
        {
            x--;
            y=1;
        }
    }
    else
    {
        y=n-l%n+1;
        if(y==n+1)
        {
            x--;
            y=n;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
