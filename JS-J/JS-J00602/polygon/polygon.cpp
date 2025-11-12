#include<bits/stdc++.h>
using namespace std;
int n,a[6000],m,ans,c;
bool cmp(int x,int y)
{
    return x<y;
}
void gm(int z,int w,int r)
{
    if(z>m)
    {
        c=1;
        for(int i=1;i<=w;i++)
        {
            c*=2;
        }
        ans+=c;
        ans%=998244353;
        return;
    }
    for(int i=w;i>=max(3-r,0);i--)
    {
        gm(z+a[i],i-1,r++);
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=n;i>=3;i--)
    {
        m=a[i]*2;
        gm(a[i],i-1,1);
    }
    cout<<ans;
    return 0;
}
