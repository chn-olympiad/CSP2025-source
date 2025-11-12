#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0,b[500005],c[500005],sum=1,k,d,ans;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>b[i];
    }
    cnt=b[0];
    sort(b,b+n*m,cmp);
    for(int i=0;i<n*m;i++)
    {
        if(cnt==b[i]) sum=i+1;
    }
    if(sum%n==0)
    {
        d=sum/n;
    }
    else
    {
        d=sum/n+1;
    }
    ans=d-1;
    k=sum-ans*n;
    if(d%2!=0)
    {
        cout<<d<<" "<<k;
    }
    else
    {
        cout<<d<<" "<<n-k+1;
    }


    return 0;
}
