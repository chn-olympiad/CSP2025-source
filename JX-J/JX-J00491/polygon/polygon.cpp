#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int vis[5010];
long long ans=0;
void dfs(int k,int h,int maxv,int ss,int kk)
{
    if(ss==k)
    {
        if(h>2*maxv) 
        {
            ans++;
        } 
        return ;
    }
    for(int i=kk;i<=n;i++)
    {    
       
        if(vis[i]!=1)
        {   vis[i]=1;
            
            dfs(k,h+a[i],a[i],ss+1,i+1);vis[i]=0;
        }
        
    }
    return ;
}
int main()
{    freopen("polygon.in","r",stdin);
      freopen("polygon.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++)
     {
         cin>>a[i];
     }
     sort(a+1,a+n+1);
     for(int i=3;i<=n;i++)
     {
        dfs(i,0,0,0,1);
        
     }
     cout<<ans%998244353;
    return 0;
}