#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[15];
int c[15];
bool bz[15];
int n,m;
int anss=0;
const int Mod=998244353;
void dfs(int x)
{
	if(x>n)
	{
		int nw=0;
		int ans=0;
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<endl<<endl;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||nw>=c[a[i]]) nw++;
			else ans++;
//			cout<<ans<<" "<<i<<endl<<endl;
		}
		
		if(ans>=m) anss++,anss%=Mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(bz[i]==1) continue;
		a[x]=i;
		bz[i]=1;
		dfs(x+1);
		bz[i]=0;
	}
}
int qpow(int a,int b)
{
	int res=1;
	while(b!=0)
	{
		if(b&1) res=res*a%Mod;
		a=a*a%Mod;
		b/=2;
	}
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=" "+s;
	bool bz=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			bz=1;
			break;
		}
	}

	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);	
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||c[i]==0)
			{
				printf("0");
				return 0;
			}
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%Mod;
		}
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%lld",anss);
}
