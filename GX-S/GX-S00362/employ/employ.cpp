#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
#define int long long
using namespace std;
int n,m;
int p[200010];
string ch;
int ans;
int vis[200010];
void dfs(int k,int tg)
{
   if (n-k+1+tg<m) return ;
   if (k>n) 
   {
    if (tg>=m) ans++;
    return ;
   }
   for (int i=1;i<=n;i++)
   {
      if (vis[i]==0)
      {
         if (p[i]<=k-tg-1 || ch[k-1]=='0')
         {
            vis[i]=1;
            dfs(k+1,tg);
            vis[i]=0;
         }
         else 
         {
            vis[i]=1;
            dfs(k+1,tg+1);
            vis[i]=0;
         }    
      }
   }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>ch;
    for (int i=1;i<=n;i++)
        scanf("%lld",p+i);
    dfs(1,0);
    cout<<ans;
    return 0;
}

