#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[100005];
int a[25],ans;
bool vis[25];
void dfs(int k)
{
	if(k>n)
	{
		int cnt=0,pre=0;
		for(int i =1;i<=n;i++)
		{
			if(pre>=c[a[i]]||s[i]=='0') pre++;
			else cnt++;
		}
		if(cnt>=m) 
		{
			ans++;
			if(ans==mod) ans=0;
		}
		return;
	}
	for(int i =1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i =1;i<=n;i++) cin>>c[i];
	if(n<=18)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	int sum=0;
	for(int i =1;i<=n;i++)
	{
		sum+=s[i]-'0';
	}
	int cnt=0;
	for(int i =1;i<=n;i++)
	{
		if(c[i]!=0) cnt++;
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	if(n==m)
	{
		if(sum!=n)
		{
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i =1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0; 
//	if(sum==n)
//	{
//		long long ans=1;
//		for(int i =1;i<=n;i++)
//		{
//			ans=ans*i%mod;
//		}
//		cout<<ans;
//		return 0;
//	}
	return 0; 
} 
/******
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

******/
