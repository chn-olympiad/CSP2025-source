#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
const int N=10010;
int a[N],b[N],k[N];
const int M=998244353;
bool vis[N];

void dfs(int x,int cnt)
{
    if(cnt==x)
    {
        int k=-2e9;
        long long sum=0;
        for(int i=0;i<cnt;i++)
        {
            sum+=b[i];
            k=max(k,b[i]);
        }
        if(sum>k*2) ans=(ans+1)%M;
        return;
    }

    for(int i=k[cnt-1];i<=n;i++)
    {
        if(vis[i]==false&&i!=0)
        {
            vis[i]=true;
            b[cnt]=a[i];
            k[cnt]=i;

            dfs(x,cnt+1);
            vis[i]=false;
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=3;i<=n;i++)
      dfs(i,0);

    cout<<ans<<endl;
    return 0;
}
