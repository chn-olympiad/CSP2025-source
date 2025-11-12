#include<bits/stdc++.h>
using namespace std;
int n,flagA=1,ans=0;
int a[100005][4]={0};
void dfs(int dep,int sum1,int sum2,int sum3,int tot)
{
	if(dep>n)
	{
		ans=max(ans,tot);
		return ; 
	}
	if(sum1+1<=n/2)
		dfs(dep+1,sum1+1,sum2,sum3,tot+a[dep][1]);
	if(sum2+1<=n/2)
		dfs(dep+1,sum1,sum2+1,sum3,tot+a[dep][2]);
	if(sum3+1<=n/2)
		dfs(dep+1,sum1,sum2,sum3+1,tot+a[dep][3]);
}
void solve() {
	flagA=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]!=0 or a[i][3]!=0)flagA=0;
	}
	if(flagA)
	{
		priority_queue<int,vector<int>,less<int> > q;
		for(int i=1;i<=n;i++)q.push(a[i][1]);
		for(int i=1;i<=n/2;i++)
		{
			ans+=q.top();
			q.pop();
		}
		cout<<ans<<endl;
	}else
	{
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}
