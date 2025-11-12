#include <iostream>
using namespace std;
int n,m;
string dif;
int pnt[505];
bool vis[505];
long long fact(int a)
{
    long long ans=1;
    for(int i=1;i<=a;i++)ans=(ans*i)%998244353;
    return ans;
}
long long dfs(int k,int p,int all,int pas)
{
    if(p>all&&pas<m)return 0;
    if(p>all&&pas==m)return 1;
    if(dif[p-1]=='1'&&pnt[k]>p-1-pas)pas++;
    if(pas==m)return fact(all-p);
    long long ans=0;
    vis[k]=1;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            ans+=dfs(i,p+1,all,pas),ans%=998244353;
    }
    vis[k]=0;
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>dif;
    for(int i=1;i<=n;i++)
        cin>>pnt[i];
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=dfs(i,1,n,0),ans%=998244353;
    }
    cout<<ans;
    return 0;
}