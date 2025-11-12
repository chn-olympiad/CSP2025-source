#include<bits/stdc++.h>
using namespace std;
long n,dp[100001],rs[3],h,l=0;
struct xr
{
    long long y,r,s;
}a[100001];
bool cmp1(xr a,xr b)
{
    return a.y>b.y;
}
bool cmp2(xr a,xr b)
{
    return max(a.y,a.r)>max(b.y,b.r);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        h=0; rs[1]=1; rs[2]=0; rs[3]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].y>>a[i].r>>a[i].s;
            if(a[i].s==0&&a[i].r!=0)l=2;
            if(a[i].r==0&&a[i].s==0)l=1;
        }
        if(l==1)
        {
            sort(a+1,a+1+n,cmp1);
            for(int i=1;i<=n/2;i++)h+=a[i].y;
        }
        if(l==2)
        {
            sort(a+1,a+1+n,cmp2);
            for(int i=1;i<=n;i++)
            {
                if(a[i].y>a[i].r)
                {
                    if(rs[1]+1<=n/2){h+=a[i].y;rs[1]++;}
                    else {h+=a[i].r;rs[2]++;}
                }
                else
                {
                    if(rs[2]+1<=n/2){h+=a[i].r;rs[2]++;}
                    else {h+=a[i].y;rs[1]++;}
                }
            }
        }
        cout<<h<<endl;
    }
    return 0;
}
