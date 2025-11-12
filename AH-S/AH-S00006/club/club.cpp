#include<bits/stdc++.h>
using namespace std;
int n;
int a[4][205];
long long answer;
void dfs(int suma,int sumb,int sumc,int i,long long ans)
{//cout<<suma<<" "<<sumb<<" "<<sumc<<" "<<i<<" "<<ans<<endl;
       if(i==n)
       {
		   answer=max(answer,ans);
		   return;
	   }
		if(suma<n/2) dfs(suma+1,sumb,sumc,i+1,ans+a[1][i+1]);
		if(sumb<n/2) dfs(suma,sumb+1,sumc,i+1,ans+a[2][i+1]);
		if(sumc<n/2) dfs(suma,sumb,sumc+1,i+1,ans+a[3][i+1]);
}
void dfs1(int suma,int sumb,int i,long long ans)
{
       if(i==n)
       {
		   answer=max(answer,ans);
		   return;
	   }
		if(suma<n/2) dfs1(suma+1,sumb,i+1,ans+a[1][i]);
		if(sumb<n/2) dfs1(suma,sumb+1,i+1,ans+a[2][i]);
}
int main()
{
	  freopen("club.in","r",stdin);
	  freopen("club.out","w",stdout);
	  int t;
	  scanf("%d",&t);
	  while(t--)
	  {
	      answer=0;
	      bool flaga=1,flagb=1;
		  scanf("%d",&n);
		  for(int i=1;i<=n;i++)
		  {
			  scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
			  if(a[2][i]) flaga=0;
			  if(a[3][i]) flagb=0;
		  }
		  if(flaga)
		  {
			  sort(a[1]+1,a[1]+n+1,greater<int>());
			  for(int i=1;i<=n/2;i++)
			       answer+=a[1][i];
		  }
		  else if(flagb) dfs1(0,0,0,0);
		  else dfs(0,0,0,0,0);
		  printf("%lld\n",answer);
	  }
	  return 0;
}
