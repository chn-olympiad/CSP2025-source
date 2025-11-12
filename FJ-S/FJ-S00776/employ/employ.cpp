#include<bits/stdc++.h>
using namespace std;
const long long modd=998244353;
int n,m,s[510],c[510],last[510];
int sums,ans,sumc;
bool v[510];
void fun0()
{
	cout<<'0'<<endl;
	exit(0);
}
void dfs(int to,int k)
{
	if(to>n)
	{
		if(k>=m)
		{
			ans++;
			ans%=modd;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	if(!v[i])
	{
		if(s[to])
		{
			if(c[i]<last[to])
			{
				v[i]=1;
				dfs(to+1,k);
				v[i]=0;
			}
			else
			{
				v[i]=1;
				dfs(to+1,k+1);
				v[i]=0;
			}
		}
		else
		{
			v[i]=1;
			dfs(to+1,k);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=0;
	string s1;
	cin>>s1;
	for(int i=1;i<=n;i++)
	{
		s[i]=s1[i-1]-'0';
		if(s[i])
		{
			last[i]=i-l;
			l=i;
			sums++;
		}
		//cout<<s[i]<<'*';
	}
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		sumc+=(c[i]==0);
	}
	if(sums<m) fun0();
	if(n-sumc<m) fun0();
	if(n<=25)
	{
		dfs(1,0);
		printf("%d\n",ans);
		return 0;
	}
	if(m==n)
	{
		if(sumc) fun0();
		else
		{
			long long tot=1;
			for(int i=2;i<=n;i++)
			{
				tot*=i;
				tot%=modd;
			}
			printf("%lld\n",tot);
			return 0;
		}
	}
	if(sums==n)
	{
		if(sumc>n-m) fun0();
		else
		{
			long long tot=1;
			for(int i=2;i<=n;i++)
			{
				tot*=i;
				tot%=modd;
			}
			printf("%lld\n",tot);
			return 0;
		}
	}
	printf("1");
	return 0;
}