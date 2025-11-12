#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=500;
int n,m,pl=1;
int ans=0;
int fff;
char s[N+5];
int c[N+5];
bool bk[N+5];
int which[N+5];
void dfs(int now)
{
	if(now>=n+1)
	{
//		fff++;
		int qv=0;
		fff=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i] && c[which[i]]>fff) qv++;
			else fff++;
//			cout<<fff<<"\n";
		}
			
		if(qv>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!bk[i])
		{
			bk[i]=1;
			which[now]=i;
			dfs(now+1);
			bk[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string cc;
	cin>>cc;
	for(int i=1;i<=n;i++)
		s[i]=cc[i-1] -'0';
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(m==1)
	{
		
		int ftg=0;
		for(int i=1;i<=n;i++)
			if(s[i]==1)
			{
				ftg=i;
				break; 
			} 
		if(ftg==0)
		{
			cout<<0;
			return 0;
		}
//		cout<<ftg<<"\n";
		for(int i=n-1;i>=2;i--)
		{
			pl*=i;
			pl%=mod;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) 
				if(c[j]+1>=i && s[i])
				{
//					cout<<"sdljfvld\n";
					ans+=pl;
					ans%=mod;
				}
		cout<<ans<<'\n';
		return 0;
	}
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
/*
3 1
011
1 0 1
*/
