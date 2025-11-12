#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int aa1[100001],aa2[100001],aa3[100001];
int ans;

void dfs(int i,int c1,int c2,int c3,int sum)
{
	if(i>n)
	{
		ans=max(ans,sum);
		return ;
	}
	if(c1+1<=n/2) dfs(i+1,c1+1,c2,c3,sum+aa1[i]);
	if(c2+1<=n/2) dfs(i+1,c1,c2+1,c3,sum+aa2[i]);
	if(c3+1<=n/2) dfs(i+1,c1,c2,c3+1,sum+aa3[i]);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>aa1[i]>>aa2[i]>>aa3[i];
		if(n<=20)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			ans=0;		
		}
		else if(aa2[1]==0 && aa3[1]==0)
		{
			sort(aa1+1,aa1+n+1);
			for(int i=0;i<n/2;i++)
			{
				ans+=aa1[n-i];	
			} 
			cout<<ans;
			ans=0;
		}
	}
	return 0;
}
