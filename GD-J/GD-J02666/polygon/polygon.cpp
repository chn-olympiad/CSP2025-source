#include<bits/stdc++.h>
using namespace std;
int n,mod=998244353,ans,a[5005],v[5005],uu,oo;
int c[5005][5005];
void dfs(int n,int pos,int m,int o,int sum,int tt)
{
	if(oo)return ;
	if(pos==m+1)
	{
		uu++;
		if(sum>tt)
		{
			oo=uu;
			return ;
		}
		return ;
	}
	for(int i=o;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1; 
			dfs(n,pos+1,m,i+1,sum+a[i],tt);
			v[i]=0;
			if(oo)return ;
		 } 
		
	}
}
signed main()
{
	//ccf is "good"
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout); 
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   c[1][0]=c[1][1]=1;
   	for(int i=2;i<=n;i++)
   	{
   		c[i][0]=1;
   	    for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
  	}
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+1+n);
   if(a[n]==1)
   {
   		
   	   for(int i=3;i<=n;i++)ans=ans+c[n][i],ans%=mod;
   	   cout<<ans;
		  return 0;
   } 
   if(n<=20)
   {
   	  int u=(1<<n)-1;
   	  for(int S=0;S<=u;S++)
   	  {
   	  	int mx=0,s=0,o=0;
   	  	for(int i=1;i<=n;i++)
   	  	{
   	  		int t=1<<(i-1);
			 if(t&S)mx=max(mx,a[i]),s+=a[i],o++;
		}
		if(s>mx*2&&o>=3)ans++;
		ans%=mod;
	  }
	  cout<<ans;
	  return 0;
   }
   for(int i=3;i<=n;i++)
   {
   	   for(int j=2;j<i;j++)
   	   {
   	   	   oo=0,uu=0;
   	   	   dfs(i-1,1,j,1,0,a[i]);
   	   	   int t=c[i-1][j];
   	   	   if(oo==0)continue;
   	   	   ans=ans+t-oo+1;
   	   	   ans%=mod;
	   }
   }
   cout<<ans;
  return 0;
}

