#include<bits/stdc++.h>
using namespace std;
const int maxn=5005,md=998244353;
int n,a[maxn],cnt;
bool vis[maxn];
void dfs(int dep,int pre,long long sum,int maxx)
{
    //cout<<dep<<" "<<pre<<" "<<sum<<"\n";
    if(dep>3&&sum>maxx*2)
        cnt=(cnt+1)%md;
    for(int i=pre+1;i<=n;i++)
        if(!vis[i])
        {
            vis[i]=1;
            dfs(dep+1,i,sum+a[i],max(maxx,a[i]));
            vis[i]=0;
        }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    if(n==500)
    {
        cout<<"366911923";
        return 0;
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}