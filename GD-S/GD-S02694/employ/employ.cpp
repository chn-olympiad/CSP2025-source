#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n,m,c[510],jc[510],a[510],cnt;
bool v[510];
string s;
long long ans;

void dfs(int id)
{
	if(id==m+1)
	{
		int l=0;
		for(int i=1;i<=m;i++)
		{
			if(l>=c[a[i]])
			{
				//cerr<<a[i]<<" ";
				return;
			}
			if(s[i]=='0')l++;
		}
		ans=(ans+jc[n-m])%998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			a[id]=i;
			dfs(id+1);
			v[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	jc[1]=1;
	for(int i=2;i<=n-m;i++)jc[i]=jc[i-1]*i%998244353;
	dfs(1);
	cout<<ans;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3



100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/
