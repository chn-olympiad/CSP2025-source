#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,tem,c,r;
bool cmp(int p,int q)
{
    return p>q;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x)
        {
            tem=i;
            break;
        }
    }
    c=ceil(tem/(n*1.0));
    r=tem%n;
    if(r==0)r=n;
    if(!(int(ceil(tem/(m*1.0)))%2))r=n-r+1;
    cout<<c<<' '<<r;
    return 0;
}
