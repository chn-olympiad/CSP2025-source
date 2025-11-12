#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
const int mod=998244353;
int c[505];
int f[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)cnt--;
	} 
	f[1]=1;
	for(int i=2;i<=cnt;i++)
	{
	 	f[i]=f[i-1]*2%mod;
	} 
	cout<<f[cnt];
	return 0;
 } 
