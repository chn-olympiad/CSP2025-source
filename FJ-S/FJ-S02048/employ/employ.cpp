#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[510];
int n,m,ansn=0;
int pai[20],vis[20];
string s;
void dfs(int k)
{
	if(k==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='0'||cnt>=c[pai[i]])
			{
				++cnt;
			}
		}
		if(n-cnt>=m)
		{
			++ansn;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			pai[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;++i)cin>>c[i];
	int flagB=1;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			flagB=0;
			break;
		}
	}
	if(flagB)
	{
		
	}
	if(n<=18)
	{
		dfs(1);
		cout<<ansn<<"\n";
		return 0;
	}
 }

