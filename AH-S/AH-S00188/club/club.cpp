#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001],n,t,mi=-1;
void dfs(int i,int e1,int e2,int e3,int s)
{
	if(i>n)
	{
		mi=max(mi,s);
		return ;
	}
	if(e1<n/2)
	{
		dfs(i+1,e1+1,e2,e3,s+a[i]);
	}
	if(e2<n/2)
	{
		dfs(i+1,e1,e2+1,e3,s+b[i]);
	}
	if(e3<n/2)
	{
		dfs(i+1,e1,e2,e3+1,s+c[i]);
	}
}
void df(int i,int e1,int e2,int s)
{
	if(i>n)
	{
		mi=max(mi,s);
		return ;
	}
	if(e1<n/2)
	{
		df(i+1,e1+1,e2,s+a[i]);
	}
	if(e2<n/2)
	{
		df(i+1,e1,e2+1,s+b[i]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n;
		int f=0,f1=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)
			{
				f=1;
			}
			if(c[i]!=0)
			{
				f=1;
				f1=1;
			}
		}
		if(f==0)
		{
			int s=0;
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2+1;i--)
			{
				s+=a[i];
			}
			cout<<s<<endl;
			continue;
		}
		if(f1==0)
		{
			mi=-1;
			df(1,0,0,0);
			cout<<mi<<endl;
			continue;
		}
		mi=-1;
		dfs(1,0,0,0,0);
		cout<<mi<<endl;
	}
	return 0;
}

