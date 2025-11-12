#include<bits/stdc++.h>
using namespace std;
int n,m;
string S;
const int maxn=500,moder=998244353;
int c[maxn+5],p[maxn+5],passed[maxn+5];
long long fact()
{
	long long mul=1;
	for (int i=1;i<=n;i++) mul=(mul*i)%moder;
	return mul;
}
bool tested[maxn+5];
int cnt;
void dfs(int pos)
{
	if (pos==n+1)
	{
		int gaveup=0;
		for (int i=1;i<=n;i++)
		{
			if (S[i]=='1'&&gaveup+(i-1-passed[i-1])>=c[p[i]]) gaveup++;
		}
		if (passed[n]-gaveup>=m) cnt=(cnt+1)%moder;
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!tested[i])
		{
			p[pos]=i;
			tested[i]=true;
			dfs(pos+1);
			tested[i]=false;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>S;
	S=" "+S;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		passed[i]=passed[i-1]+(S[i]-'0');
	}
	if (n>10) cout<<fact();
	else
	{
		dfs(1);
		cout<<cnt;
	}
	return 0;
}
