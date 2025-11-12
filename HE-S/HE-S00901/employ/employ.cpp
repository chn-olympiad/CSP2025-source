#include <bits/stdc++.h>
using namespace std;
int n,m;
bool a[20],vis[20];
int c[20];
int ans=0;
void dfs(int dep,int u)
{
	if(dep>n) {
		if(n-u>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			vis[i]=1;
			if(u>=c[i]||!a[dep]) dfs(dep+1,u+1);
			else dfs(dep+1,u);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) {
		a[i]=(s[i-1]=='0')?0:1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=20) {
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
