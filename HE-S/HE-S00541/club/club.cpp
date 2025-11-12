#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node
{
	int d1,d2,d3;
}a[100001];
bool cmp(node x,node y)
{
	return x.d1>y.d1;
}
void aa()
{
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++)
	{
		ans+=a[i].d1;
	}
	cout<<ans;
}
void bb(int k1,int k2,int s,int m)
{
	if(m==n+1)
	{
		ans=max(ans,s);
		return;
	}
	if(k1!=n/2)
	{
		bb(k1+1,k2,s+a[m].d1,m+1);
	}
	if(k2!=n/2)
	{
		bb(k1,k2+1,s+a[m].d2,m+1);
	}
	return;
}
void dfs(int k1,int k2,int k3,int s,int m)
{
	if(m==n+1)
	{
		ans=max(ans,s);
		return;
	}
	if(k1!=n/2)
	{
		dfs(k1+1,k2,k3,s+a[m].d1,m+1);
	}
	if(k2!=n/2)
	{
		dfs(k1,k2+1,k3,s+a[m].d2,m+1);
	}
	if(k3!=n/2)
	{
		dfs(k1,k2,k3+1,s+a[m].d3,m+1);
	}
	return;
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
		int f1=0,f2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d2!=0)
			{
				f1=1;
			}
			if(a[i].d3!=0)
			{
				f2=1;
			}
		}
		if(!f1&&!f2)
		{
			aa();
			return 0;
		}
		else if(f2==0)
		{
			bb(0,0,0,1);
			return 0;
		}
		dfs(0,0,0,0,1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
