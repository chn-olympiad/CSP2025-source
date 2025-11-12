#include<bits/stdc++.h>
#define int long long
using namespace std;
struct T
{
    int max1,max2,cha,x1,x2;
};
int n,gs,a[100010],b[100010],c[100010],dp[100010],maxx[100010],maxx2[100010],jl[4],t,a2,b2,c2;
T f[100010];
bool comp(T x,T y)
{
    return x.cha>y.cha;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        jl[1]=0;
        jl[2]=0;
        jl[3]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
            cin>>a[i]>>b[i]>>c[i];
            f[i].max1=max(max(a[i],b[i]),c[i]);
            f[i].max2=min(min(max(a[i],b[i]),max(a[i],c[i])),max(b[i],c[i]));
            f[i].cha=f[i].max1-f[i].max2;
            if(f[i].max1==a[i])
            {
                f[i].x1=1;
            }
            else if(f[i].max1==b[i])
            {
                f[i].x1=2;
            }
            else if(f[i].max1==c[i])
            {
                f[i].x1=3;
            }
            if(f[i].max2==c[i])
            {
                f[i].x2=3;
            }
            else if(f[i].max2==b[i])
            {
                f[i].x2=2;
            }
            else if(f[i].max2==a[i])
            {
                f[i].x2=1;
            }


        }
        sort(f+1,f+n+1,comp);
        for(int i=1;i<=n;i++)
        {
            if(jl[f[i].x1]==n/2)
            {
                dp[i]=dp[i-1]+f[i].max2;
            }
            else
            {
                jl[f[i].x1]++;
                dp[i]=dp[i-1]+f[i].max1;
            }
        }
        cout<<dp[n]<<endl;
    }
}
