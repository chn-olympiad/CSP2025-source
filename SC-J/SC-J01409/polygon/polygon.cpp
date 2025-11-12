#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n;
long long ans;
long long a[N],dp[N][N];
long long c(long long m,long long d)
{
	int num1=1,num2=1;
	for(int i=1;i<=m;i++)
	{
		num1*=d-i+1,num2*=i;
	}
	return num1/num2;
}
void dfs(int k,long long sum,long long maxx,int now)
{
	if(k==n+1)
	{
		if(maxx*2<sum&&now>=3) 
		{
			//cout<<maxx<<' '<<sum<<endl;//调试，记得注释掉 
			ans=(ans+1)%mod;
		}
		return;
	}
	k++;
	dfs(k,sum+a[k],max(maxx,a[k]),now+1);
	dfs(k,sum,maxx,now);
}//24pts
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);//正式提交 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==1)
	{
		long long ans=0;
		for(int i=3;i<=n;i++)
		{
			ans=(ans+c(i,n))%mod;
		}
		cout<<ans;
		return 0;
	}//24pts
	dfs(0,0,0,0);
	cout<<ans/2;//实在不行就把dfs交上去
	
//	dp[0]=0;
//	for(int i=1;i<=n;i++)
//	{
//		dp[i][]+=dp[i-1];
//		for()
//	}
	return 0;
}/*2022年开始学信竞，那年csp是线上考，初学者J组初赛34分，没有三等；学了1年后又来（2023年），J初赛38分，依旧没过；再学一年（2024年）后，J初赛82.5，S是41.5.
J组复赛200分，第三题爆0；今年依旧挑战，J组79.5，S组71.5，现在就是希望J组能拿个一等，S组能拿个二等就知足了。希望CCF对我好一点，让我过吧QAQ。 
小作文完成时间：11：25*/ 