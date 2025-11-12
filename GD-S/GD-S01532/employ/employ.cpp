#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int n,m,s[N],ans,use[N],cc[N];
void dfs(int now,int suc)
{
	if(now>n)
	{
		if(suc>=m)ans++;
		return;
	}
	if(n-now+1+suc<m)return;
	for(int i=1;i<=n;i++)if(!use[i])
	{
		use[i]=1;
		if(now-suc-1>=cc[i]||s[now]==0)dfs(now+1,suc);
		else dfs(now+1,suc+1);
		use[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='1')s[i]=1,cnt++;
	}
	for(int i=1;i<=n;i++)cin>>cc[i];
	if(cnt<m)cout<<0;
	else if(n<=11)
	{
		dfs(1,0);
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
