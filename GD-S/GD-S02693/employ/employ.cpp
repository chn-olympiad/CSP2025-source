#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAXN=1e4+100;
int n,m;
string s;
int o;
int c[MAXN];
int b[MAXN];
int d[MAXN];
long long ans;
int jc(int x)
{
	long long aans=1;
	for (int i=1;i<=x;i++)
	{
		aans=(aans*i)%MOD;
	}
	return aans%MOD;
}
int kk;
void dfs(int x)
{
	if (x>n)
	{
		kk++;
		int nobody=0,aans=0;
		for (int i=1;i<=x;i++)
		{
			
			if (s[i-1]=='0')
			{
				
				nobody++;
			}
			else
			{
				if (nobody<c[d[i]])
				{
					aans++;
				}
				else
				{
					nobody++;
				}
			}
		}
		if (aans>=m)
		{
			ans++;
		}
//		cout<<aans<<endl;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!b[i])
		{
			b[i]=1;
			d[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='1') o++;
	}
	int nobody=0;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (c[i]==0) nobody++;
	}
//	cout<<nobody<<endl;
	if (s.size()==o)
	{
		ans=1;
//		cout<<nobody<<endl;
		long long up=jc(n-nobody);
//		cout<<up<<" "<<dow<<endl;
//		for (int i=1;i<=n-nobody;i++)
//		{
//			ans=ans*i%MOD;
//		}
		cout<<jc(m)*jc(n-m)%MOD;
		return 0;
	}
	else if (m==n)
	{
		cout<<0;
		return 0;
	}
	else if (m==1)
	{
		ans=1;
		int al=0;
		for (int i=0;i<s.length();i++)
		{
			if (s[i]=='0') al++;
			else break;
		}
		nobody=0;
		for (int i=1;i<=n;i++)
		{
			c[i]-=al;
			if (c[i]<=0) nobody++;
		}
//		cout<<nobody<<endl;
		long long up=jc(n-nobody);
		long long dow=jc(n-m);
//		cout<<up<<" "<<dow<<endl;
		cout<<(n-nobody)*dow%MOD;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
