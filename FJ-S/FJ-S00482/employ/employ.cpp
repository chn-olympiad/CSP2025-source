#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	bool flag=1;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (s[i]!='1') flag=0;
		int x; scanf("%d",&x);
		if (!x) flag=0;
	}
	if (!flag) return puts("0"),0;
	long long ans=1;
	for (int i=1;i<=n;i++) ans=ans*i%mod;
	printf("%lld",ans);
	return 0;
}
