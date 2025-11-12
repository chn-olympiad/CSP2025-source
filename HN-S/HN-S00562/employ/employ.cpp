#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,t[555],cnt=0;
array<int,2> c[555];
long long ans;
string s;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s='#'+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i][0];
		t[c[i][0]]++;
		c[i][1]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			cnt++;
		}
	}
	if(n-t[0]-cnt<m)
	{
		cout<<0;
		return 0;
	}
	if(n<=10)
	{
		ans=0;
		sort(c+1,c+n+1);
		do
		{
			int fq=0;
			for(int i=1;i<=n;i++)
			{
				if(fq>=c[i][0]||s[i]=='0')fq++;
			}
			if(n-fq>=m)ans++;
		}while(next_permutation(c+1,c+n+1));
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		if(t[0] || cnt)
		{
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
