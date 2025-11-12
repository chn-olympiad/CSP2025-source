#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],p[505],ans;
char c[505];
bool v[505];
void dfs(int pl[505],bool vis[505],int x,int C,int s)
{
	//cout<<x<<endl;
	//cout<<s<<endl;
	if(n-x<m-s) return;
	if(x==n)
	{
		if(s>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			pl[x+1]=i;
			vis[i]=1;
			if(C>=a[pl[x+1]]) C++;
			else if(c[x+1]=='0') C++;
			else s++;
			dfs(pl,vis,x+1,C,s);
			if(C>=a[pl[x+1]]) C--;
			else if(c[x+1]=='0') C--;
			else s--;
			vis[i]=0;
			pl[x+1]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(c+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(p,v,0,0,0);
	cout<<ans;
}
