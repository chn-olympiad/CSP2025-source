#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
const int N=5005;
ll a[N];
const ll M=998244353;
ll ans;

void dfs(int step,ll sum,ll maxn,int cnt)
{
    if(step>n)
    {
        if(cnt>=3 && sum>2*maxn)
        {
            ans++;
            ans%=M;
        }
        return;
    }
    dfs(step+1,sum,maxn,cnt);
    dfs(step+1,sum+a[step],max(maxn,a[step]),cnt+1);
}

ll ksm(ll a,int b,ll p)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans=ans*a;
            ans%=p;
        }
        a=a*a;
        a=a%p;
        b/=2;
    }
    return ans;
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    ll maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(maxn==1)
    {
        ans=ksm(2,n,M)-1-n-(n-1)*n/2;
        ans=(ans%M+M)%M;
        cout<<ans;
        return 0;
    }
    else if(n<=20)
    {
        dfs(1,0,-2e9,0);
        cout<<ans<<endl;
        return 0;
    }

    return 0;
}
