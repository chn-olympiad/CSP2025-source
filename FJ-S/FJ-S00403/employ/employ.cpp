#include<bits/stdc++.h>
using namespace std;
int n,m,p,t[111111],vis[111111];
bool f[222][222][222];
long long ans;
const int mod=998244353;
string s;
void dfs(int k,int l,int q)
{
	if(f[k][l][q]==1)
	return;
	f[k][l][q]=1;
	if(k>n||l>p)
	return;cout<<k<<" "<<l<<" "<<q<<endl;
	dfs(k+1,l,q+1);
	if(q<t[k] && (l+1)<=p)
	{
		if((l+1)>=m)
		{
			ans++;
			ans%=mod;
			
		}
		dfs(k+1,l+1,q);
	}	
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1')
		p++;
	}
	if(p==n)
	{
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			vis[i]+=vis[i-1];
			if(vis[i]>=x)
			{
				vis[i+1]++;
				p--;
			}	
		}
		ans=1;
		for(int i=p;i>=1;i--)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	cin>>t[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
