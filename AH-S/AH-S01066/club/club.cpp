#include<bits/stdc++.h>
using namespace std;
int n,t;
struct node{
	int x,y,z;
};
node a[100001];
int ans=0;
void dfs(int p,int l1,int l2,int l3,int step)
{
	if(p==n+1)
	{
		ans=max(ans,step);
		return ;
	}
	if(l1<n/2)
	{
		dfs(p+1,l1+1,l2,l3,step+a[p].x);
	}
	if(l2<n/2)
	{
		dfs(p+1,l1,l2+1,l3,step+a[p].y);
	}
	if(l3<n/2)
	{
		dfs(p+1,l1,l2,l3+1,step+a[p].z);
	}
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
			cin>>a[i].x>>a[i].y>>a[i].z;
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
