#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int c[520];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=1;
	string a;
	scanf("%d%d",&n,&m);
	cin>>a;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=2;i<=n;i++) ans=(ans*i)%mod;
	printf("%lld",ans);
	return 0;
}
