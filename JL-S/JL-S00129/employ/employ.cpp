#include <bits/stdc++.h>
using namespace std;
long long n,m,x[505],a[505],v[505];
long long cnt;
char s[505];
int hs()
{
	long long nx=0,h=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0')nx++;
		else if(a[i]>nx)h++;
		if(h>=m)return 1;
		else if(n-i+h<m)return 0;
	}

	return 0;
}
void dfs(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=1;
			a[k]=x[i];
			if(k==n)
			{
				cnt+=hs();
				cnt%=998244353;
			}
			else dfs(k+1);
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
	for(int i=1;i<=n;i++)cin>>x[i];
	dfs(1);
	cout<<cnt;
	return 0;
}
