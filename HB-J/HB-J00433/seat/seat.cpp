#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],rscore,rseat,c,r;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1) rscore=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==rscore) rseat=i;
    }
    c=((rseat%n==0)?(rseat/n):(rseat/n+1));
    r=rseat-(c-1)*n;
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
