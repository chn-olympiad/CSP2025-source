#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n;
int a[5010];
long long ans=0;
int maxx=-1;
bool cmp(int x,int y)
{
	return x>y;
}
//int b[5010],st;
int vis[1<<21];
void dfs(int now,int mx,int sum,int v)
{
	if(sum>2*mx && vis[v]==0 && mx!=-1) 
	{
		//ans+=(n-now+1),ans%=Mod;
		ans++;
		ans%=Mod;
		vis[v]=1;
//		for(int i=1;i<=st;i++)
//		{
//			cout<<b[i]<<' ';
//		}
//		cout<<endl;
		//return ;
	}
	if(now==n+1) return;
	
	//选
	//b[++st]=a[now];
	dfs(now+1,max(mx,a[now]),sum+a[now],v|(1<<now));
	//st--;
	
	//不选
	dfs(now+1,mx,sum,v);
}
long long qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b%2==1)
		{
			ret*=a;
			ret%=Mod;
			b--;
		}
		a=(a*a)%Mod;
		b>>=1;
	}
	return ret%Mod;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
	if(n<=20)
	{
		//sort(a+1,a+n+1,cmp);
		dfs(1,-1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	else if(maxx==1)
	{
		cout<<qpow(2,n)-n-((n*(n-1))/2)-1<<endl;
		return 0;
	}
	return 0;
} 