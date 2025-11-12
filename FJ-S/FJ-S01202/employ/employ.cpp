#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,mod=998244353;
string s;
int xuan[5005],vis[5005],a[5005];
bool check()
{
	int guo=0,q=0;
	for(int i=1;i<=n;i++)
	{
		if(a[xuan[i]]<=q||s[i-1]=='0')
		{
			q++;
			continue;
		}
		else
		{
			guo++;
			if(guo>=m)return true;
		}
	}
	return false;
}
void dfs(int w)
{
	if(w>n)
	{
//		for(int i=1;i<w;i++)cout<<xuan[i]<<" ";
//		cout<<"\n";
		if(check())
		{
			ans++;
			if(ans==mod)ans=0;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			xuan[w]=i;
			vis[i]=1;
			dfs(w+1);
			vis[i]=0;
			xuan[w]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int u=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')u++;
	}
	if(u<m)
	{
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
/////////////////QAQ////////////////
/////////////////Q.Q////////////////
/////////////////Q_Q////////////////
/////////////////QvQ////////////////
/////////////////Q^Q////////////////
