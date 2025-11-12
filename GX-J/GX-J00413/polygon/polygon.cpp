#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,a[5050];
int cnt;
void dfs(int k,int sum,int mx){
   if(k==n+1){
      if(sum>2*mx){
         cnt++;
         cnt=cnt%mod;
      }
      return;
   }
   dfs(k+1,sum,mx);
   dfs(k+1,sum+a[k],a[k]);
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
     cin>>a[i];
   sort(a+1,a+n+1);
   dfs(1,0,0);
   cout<<cnt%mod;
   return 0;
}
