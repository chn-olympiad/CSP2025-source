#include<bits/stdc++.h>
using namespace std;
int n,a[5005],book[5005],maxx,ans;
void dfs(int x,int sum,int z)
{
	if(sum>2*maxx && x>=3)
	{
		ans++;
		return ;
	}
	for(int i=z+1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			dfs(x+1,sum+a[i],z);
			book[i]=0;
	    }
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
	   maxx=max(maxx,a[i]);
   }
    for(int i=1;i<=n;i++)
    {
		memset(book,0,sizeof(book));
		book[i]=1;
		dfs(1,a[i],i);
    }
    cout<<ans<<endl;
   return 0;
}
