#include<bits/stdc++.h>
using namespace std;
int a[5005],t=0;
long long d,e,ans;
void sz(int sx,int step,int n)
{

    for(int i=step;i<=n-sx+1;i++)
    {int cnt=1;
        int mx=-1;
        if((n-sx+1)>=i)
        {
            sz(sx,step+1,n);
            mx=max(mx,i);
            sz(sx,step+1,n);
            cnt+=i;
            return;
        }
        else
           {
               cnt+=i;
               return;
           }
        if(cnt>2*mx)
            {
                ans++;
                return;
            }
    }
    ans=ans%998244353;
    printf("%d\n",ans);
    exit(0);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
            t++;
    }
    if(n<3)
    {
        cout<<"0"<<endl;
        return 0;
    }
    d=1,e=1;
    if(t==n)
    {
        for(int k=3;k<=n;k++)
        {
            for(int l=n;l>k;l--)
                {
                    d*=l;
                    d=d%998244353;
                }
                for(int h=2;h<k;h++)
                {
                    e*=h;
                    e=e%998244353;
                }
                ans=ans+(e/d);
                ans=ans%998244353;
        }
    }
    for(int v=3;v<=n;v++)
        sz(v,1,n);
    return 0;
}
