#include<bits/stdc++.h>
using namespace std;
struct cl{
	int a1,a2,a3;
}a[100005];
int t,n,sum,flag;
void dfs(int p1,int p2,int p3,int qw,int r)
{
	int l[4]={0,0,0,0};
	int ans=0;
	if(sum==flag)
	{
		return;
	}
	if(r==n)
	{
		ans=max(ans,qw);
		sum=max(sum,ans);
		return;
	}
	l[1]=a[r+1].a1;
	l[2]=a[r+1].a2;
	l[3]=a[r+1].a3;
	if(p1<n/2)
	{
		dfs(p1+1,p2,p3,qw+l[1],r+1);
	}
	if(p2<n/2)
	{
		dfs(p1,p2+1,p3,qw+l[2],r+1);
	}
	if(p3<n/2)
	{
		dfs(p1,p2,p3+1,qw+l[3],r+1);
	}
	return;
}
int l1[4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			flag+=max(a[i].a1,max(a[i].a2,a[i].a3));
		}
		l1[1]=a[n].a1;
		l1[2]=a[n].a2;
		l1[3]=a[n].a3;
		dfs(0,0,0,0,0);
		cout<<sum<<endl;
	}
}
