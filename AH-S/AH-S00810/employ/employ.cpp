#include<bits/stdc++.h>
using namespace std;
int n,m,c[600],comb[600];
long long ans,mod=998244353;
string s;
bool flag=true;
bool vis[600];
void dfs(int u)
{
		//~ cerr<<'#';
		//~ for(int i=1;i<=u;i++)
			//~ cerr<<comb[i]<<' ';
	if(u==n+1)
	{
		//~ cerr<<'#'<<'#';
		//~ for(int i=1;i<=n;i++)
			//~ cerr<<comb[i]<<' ';
		//~ cerr<<'\n';
		int res=0,cnt=0;
		for(int i=1;i<=n;i++)
		{
			//~ cerr<<'^'<<i<<' '<<comb[i]<<' '<<c[comb[i]]<<' '<<cnt<<'\n';
			if(cnt>=c[comb[i]])
			{
				//~ cerr<<'*'<<'\n';
				cnt++;
				continue;
			}
			if(s[i]=='0')
			{
				//~ cerr<<'&'<<'\n';
				cnt++;
				continue;
			}
			res++;
		}
		//~ cerr<<'$'<<res<<'\n';
		if(res>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)
			continue;
		comb[u]=i;
		vis[i]=true;
		dfs(u+1);
		vis[i]=false;
	}
	return;
}
int main()
{ 	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	s='#'+s+'#';
	for(int i=1;i<=n;i++)
	{
		//~ cin>>s[i];
		if(s[i]=='0')
			flag=false;
	}
	//~ cerr<<s<<'\n';
	for(int i=1;i<=n;i++)
		cin>>c[i];
	//~ for(int i=1;i<=n;i++)
		//~ cerr<<c[i]<<' ';
	//~ cerr<<'\n';
	if(flag==true)
	{
		ans=1;
		for(long long i=2;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
