#include<iostream>
#include<string>
#include<vector>
#define P 998244353
using namespace std;
vector<bool> vis;
vector<int> c;
vector<bool> s;
int n,m,ans = 0;
void dfs(int k,int fail,int allow)
{
	if(k==n)
	{
		if(allow>=m){++ans;ans%=P;}
		return;
	}
	for(int i = 0;i < n;++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(!s[k]||c[i]<=fail)
				dfs(k+1,fail+1,allow);
			else
				dfs(k+1,0,allow+1);
			vis[i] = 0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	vis.resize(n);
	s.resize(n);
	c.resize(n);
	for(int i = 0;i < n;++i)
	{
		char t;
		cin>>t;
		s[i] = t-'0';
	}
	for(int i = 0;i < n;++i)
	{cin>>c[i];vis[i] = 0;}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
