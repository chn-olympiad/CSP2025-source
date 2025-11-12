#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[50010],ans;
void dfs(int x,int y,int z,int k)
{
   if(y>2*z&&k>=3) ans++,ans%=998244353;
   if(x>n)  return ;
   for(int i=x;i<=n;i++)
   {
	  dfs(i+1,y+a[i],max(z,a[i]),k+1);
   }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&a[i]);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;	
}
