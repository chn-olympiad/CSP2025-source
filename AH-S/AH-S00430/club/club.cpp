#include<bits/stdc++.h>
using namespace std;
struct S
{
	int x,y,z;
};
S s[1000000];
int n;
long long tot;
void dfs(int i,long long sum,int k1,int k2,int k3)
{
	if(k1>n/2||k2>n/2||k3>n/2) return ;
	if(i>n)
	{
		tot=max(tot,sum);
		return ;
	}
	dfs(i+1,sum+s[i].x,k1+1,k2,k3);
	dfs(i+1,sum+s[i].y,k1,k2+1,k3);
	dfs(i+1,sum+s[i].z,k1,k2,k3+1);
	dfs(i+1,sum,k1,k2,k3);
	dfs(i+1,sum,k1,k2,k3);
	dfs(i+1,sum,k1,k2,k3);
}
void dfs2(int i,long long sum,int k1,int k2)
{
	if(k1>n/2||k2>n/2) return ;
	if(i>n)
	{
		tot=max(tot,sum);
		return ;
	}
	dfs2(i+1,sum+s[i].x,k1+1,k2);
	dfs2(i+1,sum+s[i].y,k1,k2+1);
	dfs2(i+1,sum,k1,k2);
	dfs2(i+1,sum,k1,k2);
}
void dfs3(int i,long long sum,int k1)
{
	if(k1>n/2) return ;
	if(i>n)
	{
		tot=max(tot,sum);
		return ;
	}
	dfs3(i+1,sum+s[i].x,k1+1);
	dfs3(i+1,sum,k1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	bool t2=1,t3=1;
	cin>>T;
	while(T--)
	{
		tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].x>>s[i].y>>s[i].z;
			if(s[i].y==1) t2=0;
			if(s[i].z==1) t3=0;
		}
		dfs(0,0,0,0,0);
		cout<<tot<<"\n";
	}
	return 0;
}
