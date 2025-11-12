#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=501;
int n,m; 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	long long js=1;
	for(int i=1;i<=n;i++) js=(js*i)%mod;
	printf("%lld",js);
	return 0;
}