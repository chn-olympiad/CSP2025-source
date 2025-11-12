#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],s,x,b,r,cnt,t;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>a[i];
        if(i==1)b=a[1];
    }
    sort(a+1,a+s+1);
    for(int i=s;i>0;i--)
    {
        cnt++;
        if(a[i]==b)r=cnt;
    }
    x=(r+(n-1))/n;
    t=r%n;
    cout<<x<<" ";
    if(x%2==1)
    {
        if(t==0)cout<<n;
        else cout<<t;
    }
    if(x%2==0)
    {
        if(t==0)cout<<1;
        else cout<<n-(t-1);
    }
    return 0;
}
