#include<bits/stdc++.h>
using namespace std;
char s[1005],c[1005],kk;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='0') kk++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];

		long long p=1; 
		for(int i=1;i<=m-1;i++)
		{
			p*=2;
			p%=998244353;
		}
	cout<<p;
	return 0;
}
