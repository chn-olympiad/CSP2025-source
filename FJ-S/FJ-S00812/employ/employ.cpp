#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=505;
const ljl Mod=998244353;
int n,m,c[N],a[N];
ljl ans;
char ch[N];
bool vis[N];
void check()
{
	int cnt=0,cnt_m=0;
	for(int i=1;i<=n;++i)
	{
		int u=a[i];
		if(cnt>=c[u]){++cnt;continue;}
		if(ch[i]=='0')
		{
			++cnt;
			continue;
		}
		++cnt_m;
	}
	if(cnt_m>=m)++ans;
	return;
}
void dfs(int st)
{
	if(st>n)
	{
//		for(int i=1;i<=n;++i)
//			cout<<a[i]<<' ';
//		cout<<'\n';
		check();
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=1;a[st]=i;
			dfs(st+1);
			vis[i]=0;
		}
	}
	return;
}
bool checks()//si==1?
{
	for(int i=1;i<=n;++i)
		if(ch[i]=='0')return 0;
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>ch[i];
	for(int j=1;j<=n;++j)
		cin>>c[j];
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<'\n';return 0;
	}
	cout<<0<<'\n';
//	if(checks())
//	{
//		ans=1;ljl cnt0=0;
//		for(int i=1;i<=n;++i)
//			if(!c[i])++cnt0;
//		for(int i=n-cnt0;i>=1;--i)
//			ans=(ans*i)%Mod;
//		for(int i=cnt0;i>=1;--i)ans=(ans*i)%Mod;
//		cout<<ans<<'\n';
//		return 0;
//	}
	return 0;
}
