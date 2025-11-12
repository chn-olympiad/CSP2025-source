#include<bits/stdc++.h>
using namespace std;
int t,n,f[111111][4],ans;
struct node{
	int one,two,three;
}a[111111];
bool cmp(node x,node y)
{
	return x.two>y.two;
}
void dfs(int k,int p1,int p2,int p3,int total)
{
	if(p1>(n/2)||p2>(n/2)||p3>(n/2))
	return;
	if(k>n)
	{
		ans=max(ans,total);
		return;
	}
	dfs(k+1,p1+1,p2,p3,total+a[k].one);
	dfs(k+1,p1,p2+1,p3,total+a[k].two);
	dfs(k+1,p1,p2,p3+1,total+a[k].three);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].one>>a[i].two>>a[i].three;
		}
		if(n<=200)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].two;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
