#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
long long n,m,ans;
string s;
long long c[N],a[N];
bool k0,vis[N];
void dfs(long long cnt){
	if(cnt+1==n)
	{
		long long sum=0,q=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-sum>0 and s[i-1]=='1') q++;
			sum++;
		}
		if(q>=m) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[cnt]=c[i];
			vis[i]=true;
			dfs(cnt+1);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)
		if(s[i]==0) k0=true;
	if(!k0)
	{
		long long cnt=0;
		ans=1;
		for(int i=1;i<=n;i++)
			if(c[i]==0) cnt++;
		if(n-cnt<m) 
		{
			cout<<0;
			return 0;
		}
		if(cnt==0) 
		{
			for(int i=1;i<=n;i++)
				ans=ans*i%MOD;
			cout<<ans;
		}
		else 
		{
			sort(c+1,c+n+1);
			for(int i=1;i<=n-cnt;i++)
				ans=ans%MOD*i;
			for(int i=cnt;i<=n;i++)
			{
				if(c[i]-c[i-1]-1>1) 
				{
					for(int j=1;j<=(c[i]-c[i-1]-2);j++)
						ans=ans%MOD*(cnt+1)%MOD;
				}
			}
			cout<<ans;
		}
	}
	return 0;
}
