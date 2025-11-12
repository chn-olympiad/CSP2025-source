#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const int N=1e5*5+5;
ll n,k,ans=0,maxn=-2147483640;
ll a[N],noi[N];
ll f(ll x,ll y)
{
    if(x==y)return a[x];
    if(x==1)return noi[y];
    else return noi[y]^noi[x-1];
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    noi[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        noi[i]=noi[i-1]^a[i];
    }
    //for(int i=1;i<=n;i++)printf("%d ",noi[i]);
    //printf("\n");
    for(int i=1;i<=n;i++)
    {
        ll ans=0;
        for(int j=i;j<=n;j++)
        {
            for(int x=j;x<=n;x++)
            {
                //printf("%d ",f(j,x));
                if(f(j,x)==k)
                {
                    ans++;
                    j=x+1;
                }
            }
        }
        //printf("%d\n",ans);
        maxn=max(ans,maxn);
    }
    printf("%lld",maxn);
    return 0;
}

