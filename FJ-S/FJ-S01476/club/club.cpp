#include <bits/stdc++.h>
using namespace std;
int t,n;
struct s{
	int x,y,z;
}a[100005];
int ans;
bool cmp1(s a,s b)
{
	return a.x>b.x;
}
bool cmp2(s a,s b)
{
	return a.y>b.y;
}
bool cmp3(s a,s b)
{
	return a.z>b.z;
}
void dfs(int s0,int s1,int s2,int c,int z)
{
	if (c==n+1)
	{
		if (s0<=n/2 && s1<=n/2 && s2<=n/2)
		{
			ans=max(ans,z);
		}
		return ;
	}
	dfs(s0+1,s1,s2,c+1,z+a[c].x);
	dfs(s0,s1+1,s2,c+1,z+a[c].y);
	dfs(s0,s1,s2+1,c+1,z+a[c].z);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		ans=0;
		cin>>n;
		int flaga=1,flagb=1,flagc=1; 
		for (int j=1;j<=n;j++)
		{
			cin>>a[j].x>>a[j].y>>a[j].z;
			if (a[j].y!=0 || a[j].z!=0) flaga=0;
			if (a[j].z!=0 || a[j].x!=0) flagb=0;
			if (a[j].y!=0 || a[j].x!=0) flagc=0;
		}
		if (flaga==1)
		{
			sort(a+1,a+n+1,cmp1);
			for (int j=1;j<=n/2;j++)
			{
				ans+=a[i].x;
			}
			cout<<ans;
		}
		else if (flagb==1)
		{
			sort(a+1,a+n+1,cmp2);
			for (int j=1;j<=n/2;j++)
			{
				ans+=a[i].y;
			}
			cout<<ans;
		}
		else if (flagc==1)
		{
			sort(a+1,a+n+1,cmp3);
			for (int j=1;j<=n/2;j++)
			{
				ans+=a[i].z;
			}
			cout<<ans;
		}
		else
		{
			dfs(0,0,0,1,0);
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}
//我是弱智 
//一点不会 
