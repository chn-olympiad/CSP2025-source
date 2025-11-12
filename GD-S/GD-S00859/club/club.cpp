#include<bits/stdc++.h>
using namespace std;
int a[100005][5],dp[10005][5],x[100005],ans,n;
void dfs(int res)
{
	if(res==n+1)
	{
		int y1=0,y2=0,y3=0,s=0;
		for(int i = 1;i<=n;i++)
		{
			if(x[i]==1)y1++;
			else if(x[i]==2)y2++;
			else if(x[i]==3)y3++;
			s+=a[i][x[i]];
		//	cout<<s<<" ";
		}
		//cout<<s<<" ";
		if(y1>n/2||y2>n/2||y3>n/2) return ;
		ans = max(ans,s);
	
		return ;
	}
	x[res] = 1;
	dfs(res+1);
	x[res]=2;
	dfs(res+1);
	x[res]=3;
	dfs(res+1);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i = 1;i<=n;i++)
		{
			cin >>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=10)
		{
			dfs(1);
		   cout<<ans<<endl;
		}
		
	}
	return 0;
}
