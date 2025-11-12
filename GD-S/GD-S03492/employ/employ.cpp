#include <bits/stdc++.h>
const long long mod=998244353;
using namespace std;
typedef long long ll;
int n,m;
ll ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		(ans*=i)%=mod;
	printf("%lld",ans);
	return 0;
} 
