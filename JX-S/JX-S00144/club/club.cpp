#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n;
const int maxn=201;
ll arr[maxn][3], dp[maxn][101][101];
ll f(ll i,ll a,ll b)
{
	if(i==n)
	return 0;
	if(dp[i][a][b]!=-1)
	return dp[i][a][b];
	ll p1=0,p2=0,p3=0;
	if(a<n/2)
	p1=arr[i][0]+f(i+1,a+1,b);
	if(b<n/2)
	p2=arr[i][1]+f(i+1,a,b+1);
	if(i-a-b<n/2)
	p3=arr[i][2]+f(i+1,a,b);
	dp[i][a][b]=max({p1,p2,p3});
	return dp[i][a][b];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		memset(arr,0,sizeof(arr));
		for(int j=0;j<n;j++)
		{
			cin>>arr[j][0]>>arr[j][1]>>arr[j][2];
		}
		memset(dp,-1,sizeof(dp));
		cout<<f(0,0,0)<<"\n";
	}
	return 0;
}
