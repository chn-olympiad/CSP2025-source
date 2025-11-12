#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
    ll s=0,t=1;
    char c=getchar();
    while(c<'0'&&c>'9')
    {
        if(c=='-') t=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {

        s=s*10+c-'0';
        c=getchar();
    }
    return s*t;
}
ll C(int n,int m)
{
    ll sum1=1,sum2=1;
    for(int i=1;i<=n-m;i++)
    {
        sum1*=n-i+1;
        sum2*=n-m-i+1;

    }
    return sum1/sum2;

}

ll n,a[5005],maxn=LONG_LONG_MIN,ans;
void dfs(ll sum,ll mx,ll step,ll cnt)
{

    if(cnt>=3)
    {
        //cout<<sum<<'_'<<mx<<' ';
        if(sum>mx*2)
        {
            ans++;
            ans%=998244353;

        }
    }
    if(step==n) return ;
    dfs(sum+a[step],max(mx,a[step]),step+1,cnt+1);
    dfs(sum,mx,step+1,cnt);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
    {

        a[i]=read();
        maxn=max(a[i],maxn);

    }
    if(maxn!=1)
    {
        for(int i=1;i<=n-2;i++)
        {
            dfs(0,a[i],i,0);
            cout<<ans<<endl;
        }
        cout<<ans;
    }
    else
    {
        for(int i=3;i<=n;i++)
        {
            ans+=C(n,i);
        }
        cout<<ans;
    }
    return 0;
}
