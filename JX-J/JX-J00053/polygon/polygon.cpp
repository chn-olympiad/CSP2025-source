#include<bits/stdc++.h>
using namespace std;

const int MAX_N=10000;
const int MOD = 998244353;
int a[MAX_N],n,ans=0;
bool vis[MAX_N];

void solve(int k,int maxl,int sum)
{
    if(k==0)
    {
        if(sum>2*maxl)
        {
            ans=(ans+1)%MOD;
            return;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i])return;
        else
        {
            vis[i]=true;
            int l=max(maxl,a[i]);
            int s=sum+a[i];
            solve(k-1,l,s);
            vis[i]=false;
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=3;i<=n;i++)solve(i,0,0);

    cout<<ans<<endl;
    return 0;
}
