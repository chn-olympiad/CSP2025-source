#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=998244353;
string s;
long long n,m,ans,c[N],f[N];
bool v[N];
void dfs(int p)
{
	if(p>n)
	{
		int t=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0')
				t++;
			else if(t<c[f[i]])
				sum++;
			else t++;
		}
		if(sum>=m)
			ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!v[i])
		{
			f[p]=i;
			v[i]=true;
			dfs(p+1);
			v[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=11)
		dfs(1);
	else
	{ 
		int uu=0;
		for(int i=1;i<=n;i++)
			if(c[i])
				uu++;
		bool f=true;
		for(int i=0;i<s.size();i++)
			if(s[i]=='0')
				f=false;
		if(f)
		{
			ans=1;
			for(int i=1;i<=uu;i++)
				ans=ans*i%M;
		}
		if(m==1)
		{
			ll t=0;
			for(ll i=0;i<s.size();i++)
				if(s[i]=='0')
					t++;
				else break;
			for(ll i=1;i<=n;i++)
				if(c[i]>t)
				{
					long long o=1;
					 for(int i=1;i<=uu-t;i++)
						o=o*i%M;
					ans=(ans+o)%M;
				}
		}
	}
	cout<<ans<<endl;
	return 0;
}
