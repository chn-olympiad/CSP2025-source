#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

int a[5010],s[5010],n;
ll md=998244353,ans=0;

ll qpow(ll a,ll b)
{
    if(b==1) return a%md;
    if(b==0) return 1;
    ll tp=qpow(a,b>>1)%md;
    if(b&1) return tp*tp%md*(a%md)%md;
    return tp*tp%md;
}

void dfs(int i,int Max,int Sum)
{
    if(Sum>Max*2)
    {
        ans+=qpow(2,n-i);
        ans%=md;
        return;
    }
    for(int j=i+1;j<=n;j++)
    {
        dfs(j,Max,Sum+a[j]);
    }
}

ll calc(ll a)
{
    ll ans=1;
    for(ll i=2;i<=a;i++) ans*=i%md,ans%=md;
    return ans;
}

ll C(ll n,ll m)
{
    return calc(n)%md*qpow(calc(n-m),md-2)%md*qpow(calc(m),md-2)%md;
}

void run()
{
    int Max=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],Max=max(Max,a[i]);
    if(Max==1)
    {
        for(ll i=3;i<=n;i++)
        {
            ans+=C(n,i)%md;
            ans%=md;
        }
        cout<<ans;
        return;
    }
    sort(a+1,a+n+1,[](int a,int b){return a>b;});
    for(int i=1;i<=n;i++)
    {
        dfs(i,a[i],a[i]);
    }
    cout<<ans;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //ll st=clock();
    int t;
    t=1;
    while(t--)
    {
        run();
        cout<<"\n";
    }
    //cout<<clock()-st;

    return 0;
}
