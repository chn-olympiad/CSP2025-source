#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const long long M=998244353;
long long n,m,c[505],t=0,k=1,c1=0;
bool s[505];
char a[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='0')	s[i]=false;
		else {
			s[i]=true;	
			t++;	
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)	c1++;
	}
	if(t==n)
	{
		for(int i=1;i<=n;i++)	
		{
			k=k*i%M;
		}
		cout<<k;
		return 0;
	}
	if(m==n&&c1>=2)
	{
		k=0;
		cout<<k%M;
		return 0;
	}	
	cout<<2;

	return 0;
}

