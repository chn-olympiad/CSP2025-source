#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 510

int n,m;
bool v[N];
int a[N];
int sum[N];

int need[N],len;

int C[N][N];
void init()
{
	for(int i=1;i<=500;i++)C[i][0]=1;
	for(int i=1;i<=500;i++)
	{
		C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
}

int ansans=0;
void dfs(int x,int kong,int res)//第几个1，空了多少个，答案 
{
	if(x==0)
	{
		ansans=(ansans+res)%mod;
		return ;
	}
	if(len-kong<m)return;
	dfs(x+1,kong+1,res);
	int id=lower_bound(a+1,a+n+1,need[x]+kong)-a;
	dfs(x+1,kong,(res*(n-id+1-(len-x+kong)))%mod);
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
//	freopen("employ3.in","r",stdin);
	
	init();
	
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>c,v[i]=(c=='1'),len+=v[i],sum[i]=sum[i-1]+(v[i]==0);
		need[len]=sum[i];
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	
	
	if(m>len)
	{
		cout<<"0";
		return 0;
	}
	if(m==len)
	{
		int ans=1;
		cout<<len<<'\n';
		for(int i=len;i>=1;i--)
		{
			int id=lower_bound(a+1,a+n+1,need[i])-a;
			ans=(ans*(n-id+1-(len-i)))%mod;
		}
		cout<<ans;
		
		return 0;
	}
	if(len==n)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(len<=18)
	{
		dfs(1,0,1);
		
		cout<<ansans/2;
		
		return 0;
	}
	
	int ans=1;
	cout<<len<<'\n';
	for(int i=len;i>=1;i--)
	{
		int id=lower_bound(a+1,a+n+1,need[i])-a;
		ans=(ans*(n-id+1-(len-i)))%mod;
	}
	cout<<ans;
	
	return 0;
}
/*
10 10
1111111111
1 1 1 1 1 0 0 0 0 0 

*/
//补胎相认 
