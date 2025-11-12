#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],s[505],f[505],p[505],ans;
string st;
void ikun(long long k)
{
	if(k>n)
	{
		ans++;
		for(long long i=0;i<n;i++)
		{
			if(p[i]<s[i-1])
			{
				ans--;
				return;
			}
		}
		return;
	}
	for(long long i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			p[k]=i,f[i]=1;
			ikun(k+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(false);
	cin>>n>>m>>st;
	for(long long i=0;i<n;i++) cin>>a[i],s[i]=s[i-1]+st[i]-'0';
	ikun(1);
	cout<<0;
	return 0;
}
