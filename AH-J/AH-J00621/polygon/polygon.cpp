#include<bits/stdc++.h>
using namespace std;
long long s,a[50005],n;
void dfs(long long x,long long c,long long fx,long long cc)
{
	if(cc>=3)
	{
		if(fx*2<c)
		{
			s++;
		}
		if(x==n+1)
		return ;
	}
	for(int i=x;i<=n;i++)
	{
		dfs(i+1,c+a[i],max(fx,a[i]),cc+1);
	}
}
int main()
{
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)
   {
	   cin>>a[i];
   }
   sort(a+1,a+n+1);
   dfs(0,0,0,0);
   cout<<s/2;
   return 0;
}
