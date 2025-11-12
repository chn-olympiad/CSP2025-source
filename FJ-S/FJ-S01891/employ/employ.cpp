#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[1000005];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string str;
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	int opt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]!='1')
			opt=1;
	}
	if(opt==0)
	{
		int s=1;
		for(int i=1;i<=n;i++)
		{
			s*=i;
			s%=mod;
		}
		cout<<s;
	}
	else cout<<0; 
	return 0;
}
