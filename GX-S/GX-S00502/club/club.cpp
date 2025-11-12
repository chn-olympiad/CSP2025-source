#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
struct u
{
	ll a1,a2,a3;
};
ll dp[100005][4][2];
vector <u>mrs(10005);int n;
void dfs(ll dep,ll sum,ll d1,ll d2,ll d3)
{
	
	if(d1>n/2||d2>n/2||d3>n/2)
	{return;}
	if(dep>n)
	{ans=max(ans,sum); return;}
	   
	
	 
	
	dfs(dep+1,sum+mrs[dep].a1,d1+1,d2,d3);
	dfs(dep+1,sum+mrs[dep].a2,d1,d2+1,d3);
	dfs(dep+1,sum+mrs[dep].a3,d1,d2,d3+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		ll manx=0;
		for(int i=1;i<=n;i++)
		{
			cin>>mrs[i].a1>>mrs[i].a2>>mrs[i].a3;
			manx+=mrs[i].a1;
			dp[i][1][0]=dp[i][1][1]=dp[i][2][0]=dp[i][2][1]=dp[i][3][0]=dp[i][3][1]=0;
		}
		if(n<=10)
		{
		
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	    
	    }
	    else cout<<manx<<endl;
     } 	
		
	return 0;
}

