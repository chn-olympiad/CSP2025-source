#include<bits/stdc++.h>
using namespace std;
int a[10000],r[10000];
int n,ans;
void dfs(int step,int pos)
{
	if(step>3)
	{
		int maxn=INT_MIN,s=0;
		for(int i=1;i<step;i++)
		{
			maxn=max(maxn,r[i]);
			s+=r[i];
		}
		if(s>maxn*2) ans=(ans+1)%998244353;
	}
	if(step>n) return ;
	
	for(int i=pos;i<=n;i++)
	{
		r[step]=a[i];
		dfs(step+1,i+1);
	}
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   dfs(1,1);
   cout<<ans;
   return 0;
}
//2 3 3 0
