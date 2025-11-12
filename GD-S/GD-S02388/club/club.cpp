#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
struct mem
{
	int a,b,c;
}p[2000005];
int ans,n;
void dfs(int x,int count_a,int count_b,int count_c,int ansl)
{
	if(count_a>(n>>1)||count_b>(n>>1)||count_c>(n>>1))
	{
		return;
	}
	if(x==n+1)
	{
		ans=max(ans,ansl);
		return;
	}
	for(int i=x;i<=n;i++)
	{
		dfs(i+1,count_a+1,count_b,count_c,ansl+p[i].a);
		dfs(i+1,count_a,count_b+1,count_c,ansl+p[i].b);
		dfs(i+1,count_a,count_b,count_c+1,ansl+p[i].c);
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		ans=0; 
	}	
	return 0;
}

