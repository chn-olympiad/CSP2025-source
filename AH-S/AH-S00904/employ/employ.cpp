#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
char s[505];
const long long p=998244353;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		ans*=(long long)i;
		ans%=p;
	}
	printf("%lld",ans);
	return 0;
}
