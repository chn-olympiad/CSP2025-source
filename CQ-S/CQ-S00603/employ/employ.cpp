#include<bits/stdc++.h>
using namespace std;
string s;
int a[505];
const long long p=998244353;
long long A[505];
int n,m;
bool b[505];
long long ans;
int sum[505];
void dfs(int x,int cnt,int k)
{
	//cout<<x<<' '<<cnt<<'\n';
	if(x>n&&cnt>=m)
	{
		ans++;
		if(ans>=p)ans-=p;
		return;
	}
	if(cnt+(n-x+1)-(sum[n]-sum[x-1])<m)return;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			if(s[x-1]=='1'&&a[i]>k)dfs(x+1,cnt+1,k);
			else dfs(x+1,cnt,k+1); 
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	*cin.tie(nullptr)<<fixed<<setprecision(20);
	cout.tie(nullptr)->ios_base::sync_with_stdio(false);
	int cnt=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cnt+=(s[i]=='1');
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	A[0]=1;
	for(int i=1;i<=n;i++)A[i]=A[i-1]*i%p;
	if(m==1)
	{
		cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='1')
			{
				cnt=i;
				break;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt<a[i])ans=(ans+A[n-1])%p;
		}
		cout<<ans;
		return 0;
	}
	if(cnt==n)
	{
		cout<<A[n];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')sum[i]=sum[i-1]+1;
		else sum[i]=sum[i-1];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
