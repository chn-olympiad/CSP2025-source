#include<bits/stdc++.h>
using namespace std;
int n,m,df;
char s[505];
int c[505],f[100000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
			f[i]=f[i-1]+2;
	}
	cout<<f[n]%998244353;
	return 0;
}

