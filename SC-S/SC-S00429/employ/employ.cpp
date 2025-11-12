#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
long long ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
		ans=(ans*(ans+c[i])%MOD)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}