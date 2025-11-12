//GZ-S00023 玉屏侗族自治县第一中学 何子涵
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int N=1e5+5;
struct mumber
{
    int a1;
    int a2;
    int a3;
    int add;
}a[N];
int t,n,ans,ans1;
bool cmp(mumber x,mumber y)
{
    return x.a1>y.a1;
}
bool cmp1(mumber x,mumber y)
{
    return x.a2>y.a2;
}
bool cmp2(mumber x,mumber y)
{
    return x.a3>y.a3;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--)
    {
     cin >> n;
     ans=0;
     int k=n/2;
        for(int i=1;i<=n;i++)
        {
         cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
        }
     for(int l=1;l<=n;l++)
     {
        for(int i=1;i<=n;i++)
        {
         a[i].add=0;
        }
        ans1=0;
        sort(a+1,a+1+n,cmp);
        for(int i=l;i<=k+l-1;i++)
        {
            if ((a[i].a1>=a[i].a2)&&(a[i].a1>=a[i].a3))
            {
             ans1+=a[i].a1;
             a[i].add=1;
            }
        }
     sort(a+1,a+1+n,cmp1);
        for(int i=l;i<=k+l-1;i++)
        {
            if ((a[i].a2>=a[i].a3)&&(a[i].add==0))
            {
             ans1+=a[i].a2;
             a[i].add=2;
            }
        }
     sort(a+1,a+1+n,cmp2);
        for(int i=l;i<=k+l-1;i++)
        {
            if (a[i].add==0)
            {
             ans1+=a[i].a3;
             a[i].add=3;
            }
        }
      ans=max(ans,ans1);
     }
     cout << ans << endl;
    }
    return 0;
}
