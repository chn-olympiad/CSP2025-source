#include<bits/stdc++.h>
using namespace std;
int x[4],n,ans=0;
int t,b[10];
struct human
{
	int a1,a2,a3;
}a[100002];
void dfs(int xx,int ans1)
{
	if(xx>n)
	{
		ans=max(ans,ans1);
		//cout<<ans1<<"\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(b[i]==0&&x[j]<n/2)
		    {
		    	b[i]=1;
		    	x[j]++;
		    	if(j==1) dfs(xx+1,ans1+a[i].a1);
		    	if(j==2) dfs(xx+1,ans1+a[i].a2);
		    	if(j==3) dfs(xx+1,ans1+a[i].a3);
		    	x[j]--;
		    	b[i]=0;
		    }
		}
	}
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
		dfs(1,0);
		printf("%d\n",ans);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		ans=0;
	}
	return 0;
}
