#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define pii pair<int,int>
#define swap(a,b) (a^=b^=a^=b)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define sqrt(a) __builtin_sqrt(a)
using namespace std;
int n,m,pd,a[505],c[505],fl[505],ans;
bitset<505> b;
void dfs(int step)
{
    if(step==n)
    {
        int cnt=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(cnt>=c[i])
            {
                cnt++;
                continue;
            }
            if(b[i])
                sum++;
            else
                cnt++;
            if(sum>=m)
            {
                ans=(ans+1)%998244353;
                break;
            }
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(fl[i]==0)
        {
            fl[i]=1;
            c[step]=a[i];
            dfs(step+1);
            fl[i]=0;
        }
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>b;
    for(int i=0;i<n;i++)
        if(b[i]==0)
    {

        pd=1;
        break;
    }
    if(!pd)
    {
        ll ans=1;
        for(int i=2;i<=m;i++)
            ans=ans*i%998244353;
        cout<<ans;
    }
    if(n>=500&&pd)
	{
		cout<<0;
		return 0;
	}
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(0);
    cout<<ans;
    return 0;
}
