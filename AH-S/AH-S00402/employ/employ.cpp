#include<bits/stdc++.h>
using namespace std;
long long a[505],b[505],vis[505];
const long long mod=998244353;
long long n,m,c=0;
string s;
void dfs(int x,int y,int z)
{
	if(y>=m)
	{
		c=(c+b[n-x])%mod;
		return;
	}
	if(x>=n)
		return ;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			if(s[x]=='1'&&a[i]>z)
				dfs(x+1,y+1,z);
			else
				dfs(x+1,y,z+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int k=0;
	cin>>n>>m;
	cin>>s;
	b[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],k+=s[i-1]-'0',b[i]=(b[i-1]*i)%mod;
	if(n==m)
	{
		long long x=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||s[i-1]=='0')
			{
				cout<<0;
				return 0;
			}
			else
				x=(x*i)%mod;
		}
		cout<<x;
		return 0;
	}
	dfs(0,0,0);
	cout<<c;
	return 0;
}
