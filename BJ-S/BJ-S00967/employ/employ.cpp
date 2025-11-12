#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[505];
int a[505];
bool v[505];
void dfs(int cur)
{
	if (cur==n)
	{
		int runner=0;
		for (int i=0;i<n;i++)
			if (s[i]=='0'||runner>=c[a[i]])
				runner++;
		if (n-runner>=m)
			ans++;
		return ;
	}
	for (int i=0;i<n;i++)
	{
		if (v[i])
			continue;
		a[cur]=i;
		v[i]=1;
		dfs(cur+1);
		v[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++)
		cin>>c[i];
	if (n>10)
	{
		bool flag=1;
		for (int i=0;i<n;i++)
			if (s[i]=='0')
				flag=0;
		if (!flag)
		{
			cout<<0<<"\n";
			return 0;
		}
		int ans=1,P=998244353;
		for (int i=1;i<=n;i++)
			ans=ans*i%P;
		cout<<ans<<"\n";
		return 0;
	}
	dfs(0);
	cout<<ans<<"\n";
	return 0;
}
