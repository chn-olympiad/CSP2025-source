#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998224353;
int n,m;
bool dayl[505];
int c[505];
int fac(int x)
{
	int tmp=1;
	for(int i=x;i>=1;i--)
	{
		tmp*=i;
		tmp%=mod;
	}
	return tmp;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool mark=1;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='1') dayl[i]=1;
		if(dayl[i]==0) mark=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(mark)
	{
		cout<<fac(n);
		return 0;
	}
	return 0;
}
