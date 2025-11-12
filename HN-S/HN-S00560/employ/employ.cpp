#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=998244353;
int n,m,cnt,ccnt;
int c[N],vis[N],val[N];
string s;
int q(int x)
{
	ll res=1;
	for(int i=1;i<=x;++i)
		res=res*i%M;
	return res;
}
int dfs(int d)
{
	if(d==n)
	{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i-1]=='0'||cnt2>=c[val[i]])
			{
				++cnt2;
				continue;
			}
			++cnt1;
		}
		if(cnt1<m)
			return 0;
		else
			return 1;
	}
	int res=0;
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			val[d+1]=i;
			res+=dfs(d+1);
			vis[i]=0;
		}
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		if(!c[i])
			++ccnt;
	}
	for(int i=0;i<n;++i)
		if(s[i]=='1')
			++cnt;
	if(n<=10)
		cout<<dfs(0);
	else if(n==m)
	{
		if(cnt==n&&!ccnt)
			cout<<q(n);
		else
			cout<<0;
	}
	else if(cnt==n)
		cout<<q(n);
	else
		cout<<0;
	return 0;
}
