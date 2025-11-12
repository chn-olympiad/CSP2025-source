#include<bits/stdc++.h>
using namespace std;

int n;
const int N=5050;
int a[N];
bool b[N]={false};
long long ans=0;


void dfs(int step,int xigma,int mx)
{
	if(step == n)
	{
		if(xigma >= 2 * mx)ans++;
		return ;
	}
	
	for(int i=1;i<=n;i++)
	{
		b[i]=true;
		dfs(step+1,xigma+a[i],max(mx,a[i]));
		b[i]=false;
		dfs(step+1,xigma,mx);
	}
	return ;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	if(n==3)
	{
		int xigma=0,mx=-1;
		for(int i=1;i<=3;i++)
		{
			int x;
			cin>>x;
			xigma+=x;
			mx=max(mx,x);
		}
		if(xigma >= 2*mx)cout<<1;
		else cout<<0;
		return 0;
	}
	
	if(n<=10)
	{
		
		for(int i=1;i<=n;i++)cin>>a[i];
			
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++) dfs(i,0,-1);
		
		cout<<ans<<endl;
	}	
	
	return 0;
}
