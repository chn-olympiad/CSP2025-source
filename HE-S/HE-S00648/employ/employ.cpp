#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[505],t[505],vis[505],ans;
string s;
void dfs(int k,int cnt)
{
	if(k==n+1)
	{
		if(cnt>=m){
		
		ans=(ans+1)%mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		t[k]=i; vis[i]=true;
		if(k-1-cnt>=a[i]||s[k]=='0') dfs(k+1,cnt);
		else dfs(k+1,cnt+1);
		vis[i]=false; t[k]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; s='&'+s;
	bool flag1=true; int tt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!(s[i]-'0')) flag1=false;
		if(a[i]==0) tt--;
	}
	if(tt<m){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout); 
	return 0;
}
