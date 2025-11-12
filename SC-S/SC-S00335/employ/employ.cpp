#include <bits/stdc++.h>
using namespace std;
const int N=15;
const int Mod=998244353;
char h[N];	
int c[N];
int p[N];
int fac[505];
signed main()
{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	fac[0]=1;
	for(int i=1;i<=n;i++) 
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=Mod;
	}
	if(m==n)
	{
		bool flag=1;
		for(int i=1;i<=n;i++) 
		{
			if(h[i]=='0') flag=0;
			if(c[i]==0) flag=0;
		}
		if(!flag) cout<<0;
		else
		{
			cout<<fac[n];
		}
		return 0;
	}
	if(n>=13) 
	{
		int cnt0,cnt02;
		cnt0=cnt02=0;
		for(int i=1;i<=n;i++)
		{
			if(h[i]=='0') cnt0++;
			if(c[i]==0) cnt02++;
		}
		cout<<fac[n-cnt0-cnt02]+min(cnt0,cnt02);
		return 0;
	}
	int ans=0;
	do
	{
		int cnt=0;
		int scnt=0;
		for(int i=1;i<=n;i++)
		{
			int now=p[i];
			if(cnt>=c[now])
			{
				cnt++;
				continue;
			}
			if(h[i]=='0')
			{
				cnt++;
				continue;
			}
			scnt++;
		}
		if(scnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}