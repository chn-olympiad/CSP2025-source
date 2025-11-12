#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans,f[30],a[30],b[30];
void dfs(int k)
{
	if(k>n)
	{ 
		int t=0,sum=0;
		for(int i=0;i<n;i++)
		{
			if(t>=a[i]||s[i]=='0') t++;
			else sum++;
		}
		if(sum>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++) if(!f[i]) a[k-1]=b[i],f[i]=1,dfs(k+1),f[i]=0;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>b[i];
	dfs(1);
	cout<<ans;
}
//我要上迷惑行为大赏 
//freopen("employ.in","r",stdin);
//freopen("employ.in","r",stdin);
//freopen("employ.in","r",stdin);
