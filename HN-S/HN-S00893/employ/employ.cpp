#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
long long ans=1,mod=998244353;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		ans=(ans*i)%mod;
	}
	printf("%lld",ans);
	return 0;
}
