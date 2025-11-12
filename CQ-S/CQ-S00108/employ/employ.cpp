#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int c[N],a[N],n,m;
bool vis[N];
long long v[505];
long long ans;
string s;
void dfs(int x,int fq,int tg)
{
	if(x>n)
	{
		if(tg>=m) ans=(ans+1)%mod;
		return ;
	}
	if(tg>=m)
	{
		ans=(ans+v[n-x+1])%mod;
		return;
	}
	if(tg+(n-x+1)<m) return ;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			a[x]=i;
			if((s[x-1]=='1'&&fq>=c[a[x]])||s[x-1]=='0') dfs(x+1,fq+1,tg);
			else dfs(x+1,fq,tg+1);
			vis[i]=false;
		}
	}
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	cin>>s;
	bool flag=true;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++) if(s[i]=='0') flag=false;
	v[0]=v[1]=1;
	for(int i=2;i<=n;i++) v[i]=(v[i-1]*i)%mod;
	if(flag) cout<<v[n]%mod<<"\n";
	else {
		dfs(1,0,0);
		cout<<ans%mod<<"\n";		
	}
	return 0;
}
 

