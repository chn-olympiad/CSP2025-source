#include<bits/stdc++.h>
using namespace std;
int c,t,n;
int x[100005],y[100005],z[100005];
void dfs(int yj[],int ar,int br,int cr,int zh,int k)
{
	if(k>=n+1||ar==n/2&br==n/2&&cr==n/2)
	{
		c=max(c,zh);
		return ;		
	}	
	for(int i=0;i<n;i++)
	{
		if(yj[i]==1) continue;
		if(ar<n/2)
		{
			yj[i]=1;
			dfs(yj,ar+1,br,cr,zh+x[i],k+1);
			yj[i]=0;
		}
		if(br<n/2)
		{
			yj[i]=1;
			dfs(yj,ar,br+1,cr,zh+y[i],k+1);
			yj[i]=0;
		}
		if(cr<n/2)
		{
			yj[i]=1;
			dfs(yj,ar,br,cr+1,zh+z[i],k+1);
			yj[i]=0;
		}
	}
	dfs(yj,ar,br,cr,zh,k+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		c=0;
		for(int i=0;i<n;i++)
		cin>>x[i]>>y[i]>>z[i];
		int yj[n]={0};
		dfs(yj,0,0,0,0,1);
		cout<<c<<'\n';
	}	
	return 0;
}
