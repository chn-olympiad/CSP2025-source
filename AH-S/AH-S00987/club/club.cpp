#include<bits/stdc++.h>
using namespace std;
struct st
{
	int a,b,c;
}e[100010];
int r[100010],T[100010];
int t,n,maxn;
bool cmp1(st a,st b)
{
	return a.a>b.a;
}
bool cmp2(st a,st b)
{
	return a.b>b.b;
}
void dfs(int step,int t1,int t2,int t3,int ans)
{
    if(step>n)
    { 
		maxn=max(maxn,ans);
		return ;
	}	
	if(t1+1<=n/2) dfs(step+1,t1+1,t2,t3,ans+e[step].a);
	if(t2+1<=n/2) dfs(step+1,t1,t2+1,t3,ans+e[step].b);
	if(t3+1<=n/2) dfs(step+1,t1,t2,t3+1,ans+e[step].c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		maxn=INT_MIN;
		for(int i=1;i<=n;i++) cin>>e[i].a>>e[i].b>>e[i].c;
		if(n<=10)
		{
			dfs(1,0,0,0,0);
			cout<<maxn<<'\n';
		}
		else
		{
			sort(e+1,e+n+1,cmp1);
			long long ans1=0,ans2=0;
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2) ans1+=e[i].a;
				else ans1+=e[i].b;	
			}
			sort(e+1,e+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(i<=n/2) ans2+=e[i].b;
				else ans2+=e[i].a;	
			}
			cout<<max(ans1,ans2)<<'\n';
		}
		
	}
}
