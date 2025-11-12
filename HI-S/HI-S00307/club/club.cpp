#include<bits/stdc++.h>
using namespace std;
int t,n,limit;
struct node{
	long long a1,a2,a3;
}a[100100];
int k[10];
long long ans;
bool cmp(node x,node y)
{
	return x.a1>y.a1;
}
void dfs(int dep1,int dep2,int dep3,int k,long long cnt)
{
	if(k==n+1)
	{
		ans=max(ans,cnt);
		return ;
	} 
	if(k==n+1)
	{
		ans=max(ans,cnt);
		return ;
	} 
	if(dep1>0)
	{
		cnt+=a[k].a1;
		dep1--;
		dfs(dep1,dep2,dep3,k+1,cnt);
		dep1++;
		cnt-=a[k].a1;
	}
	if(dep2>0)
	{
		cnt+=a[k].a2;
		dep2--;
		dfs(dep1,dep2,dep3,k+1,cnt);
		dep2++;
		cnt-=a[k].a2;
	}
	if(dep3>0)
	{
		cnt+=a[k].a3;
		dep3--;
		dfs(dep1,dep2,dep3,k+1,cnt);
		dep3++;
		cnt-=a[k].a3;
	}
}
void dfs2(int dep1,int dep2,int dep3,int k,long long cnt)
{
	if(k==n+1)
	{
		ans=max(ans,cnt);
		return ;
	} 
	if(dep1>0)
	{
		cnt+=a[k].a1;
		dep1--;
		dfs(dep1,dep2,dep3,k+1,cnt);
		dep1++;
		cnt-=a[k].a1;
	}
	if(dep2>0)
	{
		cnt+=a[k].a2;
		dep2--;
		dfs(dep1,dep2,dep3,k+1,cnt);
		dep2++;
		cnt-=a[k].a2;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		t--;
		cin>>n;
		limit=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1==0) k[1]++;
			if(a[i].a2==0) k[2]++;
			if(a[i].a3==0) k[3]++;
		}
		if(k[2]==n&&k[3]==n)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=limit;i++)
			ans+=a[i].a1;
			cout<<ans<<endl;
			continue;
		}
		if(k[3]==n)
		{
			dfs2(limit,limit,limit,1,0);
			cout<<ans<<endl;
			continue;
		}
		dfs(limit,limit,limit,1,0);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;	
} 
