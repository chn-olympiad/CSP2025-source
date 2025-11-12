#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int ans,n,b[5010];
struct dd{int l,x;}a[5010];
bool cmd(dd x,dd y)
{
    return x.l<y.l;
}
void fs(int t,int k,int s)
{
    if(t)
        for(int i=s;i<=n;i++)
            if(!a[i].x)
            {
                b[t]=a[i].l,a[i].x++;
                fs(t-1,k,i);
                a[i].x--;
            }
    else
    {
        int h=0;
        for(int i=1;i<=k;i++)
            h+=b[i];
        if(2*b[1]<h)ans=ans%998244353+1;
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].l;
    sort(a+1,a+n+1,cmd);
    for(int k=1;k<=n;k++)
        fs(k,k,1);
    cout<<ans;
    return 0;
}
