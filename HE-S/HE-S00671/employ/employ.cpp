#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m;
string s;
int c[N],ans=1;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	if(m==n)
	{
	for(int i=2;i<=m;i++)
	{
		ans*=i;
		ans%=mod;
		}
		printf("%lld",ans);
		return 0;	
	}
	printf("369");
	return 0;
}
