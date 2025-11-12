#include<bits/stdc++.h>
using namespace std;
struct node
{
	int d1,d2,d3;
};
int n,sum=0,ans[222222],o=0;
node a[211111];
int dfs(int d1,int d2,int d3,int d,int i)
{
	ans[i]=max(ans[i],d);
	if(i==n)
	{
		return d;
	}
	int k=0,r=0,l=0;
	if(d1<n/2)
	{
		k=dfs(d1+1,d2,d3,d+a[i+1].d1,i+1);
	}
	if(d2<n/2)
	{
		r=dfs(d1,d2+1,d3,d+a[i+1].d2,i+1);
	}
	if(d3<n/2)
	{
		l=dfs(d1,d2,d3+1,d+a[i+1].d3,i+1);
	}
	return max(k,max(r,l));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			o=max(a[i].d1,max(a[i].d2,max(a[i].d3,o)));
		}
		
		sum=max(dfs(1,0,0,a[1].d1,1),max(dfs(0,1,0,a[1].d2,1),dfs(0,0,1,a[1].d3,1)));
		cout<<sum<<endl;
	}
	return 0;
}
