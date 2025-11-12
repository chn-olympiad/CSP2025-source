#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int mod=998244353;
string s;
int n,m;
int a[N];
bool vis[N];
int ans;
void dfs(int k,int sum)
{
	if(k>n)
	{
		ans=(ans+1)%mod;
		//cout<<"ans="<<ans<<endl;//
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)
		{
			continue;
		}
		if(a[i]<=sum)
		{
			//cout<<"not"<<endl;//
			continue;
		}
		vis[i]=1;
		int t=(s[k-1]=='0'?1:0);
		//cout<<k<<"->"<<i<<"  sum:"<<sum<<endl;//
		dfs(k+1,sum+t);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	//int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//cout<<0;
	dfs(1,0);
	cout<<ans;
	return 0;
}

