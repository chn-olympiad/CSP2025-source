#include<iostream>
using namespace std;
long long t,n,a[100005][4];
long long ans=-1;
void dfs(long long lev,long long n1,long long n2,long long n3,long long sum)
{
	if(lev==n+1)
	{
		if(n1>=0&&n2>=0&&n3>=0)
			ans=max(ans,sum);
		return ;
	}
	if(n1>0) dfs(lev+1,n1-1,n2,n3,sum+a[lev][1]);
	if(n2>0)dfs(lev+1,n1,n2-1,n3,sum+a[lev][2]);
	if(n3>0)dfs(lev+1,n1,n2,n3-1,sum+a[lev][3]);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(long long i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		ans=-1;
		dfs(1,n/2,n/2,n/2,0);
		cout<<ans<<endl;
	}
	return 0;
}
