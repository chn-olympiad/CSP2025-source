#include <bits/stdc++.h>
using namespace std;
int n,m,c[10001];
string s;
long long ans=1,mod=998244353 ;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}


