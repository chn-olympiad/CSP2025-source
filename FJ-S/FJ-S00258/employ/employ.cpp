#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int n,m,ans;
string s;
int c[N];
bool vis[N];
void dfs(int k,int nowm,int g)
{
//		cout<<k<<' ';
	if(k>n)
	{
		if(nowm>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			if(g>=c[i] || s[k-1]=='0') dfs(k+1,nowm,g+1);
			else dfs(k+1,nowm+1,g);
			vis[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
