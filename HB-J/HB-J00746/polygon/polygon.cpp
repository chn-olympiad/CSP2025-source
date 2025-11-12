#include <iostream>
#define MOD 998244353
using namespace std;
long long n,a[5005],ans;
bool f;
void dfs(long long t,long long maxn,long long s,long long ch)
{
    if(t>n)
    {
        if(s>maxn*2&&ch>=3)
        {
            ans=(ans+1)%MOD;
        }
        return;
    }
    dfs(t+1,maxn,s,ch);
    dfs(t+1,max(maxn,a[t]),s+a[t],ch+1);
}
long long aper(int x,int y)
{
    long long res=1;
    for(int i=x-y+1;i<=x;i++)
    {
        res=(res*i)%MOD;
    }
    return res;
}
long long cper(int x,int y)
{
    return (aper(x,y)/aper(y,y))%MOD;
}
void solve0()
{
    for(int i=3;i<=n;i++)
    {
        ans=(ans+cper(n,i));
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=1)
        {
            f=1;
        }
    }
    if(f)dfs(1,0,0,0);
    else solve0();
    cout << ans%MOD;
    return 0;
}
