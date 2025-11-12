#include<iostream>
#include<string>
using namespace std;
const int mod=998244353;
int n,m,cnt;
int c[505];
bool vis[505];
string s;
void dfs(int k,int giveup)	
//第k天，有giveup个人放弃或被拒 
{
	if(k>n)
	{
//		cout<<giveup<<"\n";
		if(n-giveup>=m)cnt++;
		cnt%=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(giveup>=c[i]||s[k-1]=='0')
				dfs(k+1,giveup+1);
			else dfs(k+1,giveup);
			vis[i]=0;
		}
	}
 } 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	int len=s.length();
	int f=0;
	for(int i=0;i<len;i++)
		if(s[i]=='0')f=1;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(!f)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(n<=10)
	{
		dfs(1,0);
		cout<<cnt;
		return 0;
	}
	if(m==1&&s[0]=='1')
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		if(f)cout<<0;
	}
	return 0;
 } 
