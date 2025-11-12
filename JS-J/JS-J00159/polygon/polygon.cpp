#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],ans;
bool vis[5005][5005];
void dfs(ll num,ll cnt,ll max_num,ll all,ll k)
{
    if(num>n or cnt>k) return;
    if(2*max_num<all and cnt==k and vis[num][max_num]==0)
    {
        ans++;
        vis[num][max_num]=1;
    }
    dfs(num+1,cnt+1,max(max_num,a[num+1]),all+=a[num+1],k);
    dfs(num+1,cnt,max_num,all,k);
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=3;i<=n;i++) dfs(0,0,0,0,i);
   cout<<ans;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
