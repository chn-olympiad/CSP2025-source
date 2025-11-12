#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,i,pat[1001],op=1;
	char a[1001];
	scanf("%lld%lld",&n,&m);
	scanf("%s",a);
	for(i=1;i<=n;i++){
		scanf("%lld",&pat[i]);
	}
	for(i=1;i<=n;i++){
		op=(op*i)%998244353;
	}
	printf("%lld",op);
	return 0;
}
