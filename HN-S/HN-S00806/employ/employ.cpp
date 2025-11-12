#include<bits/stdc++.h>
using namespace std;
char s[501];
int c[501];
long long ans=1;
long long sum=0;
int temp=0;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d\n",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%c",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==0){
			temp++;
		}
	}
	if(n-temp<m){
		printf("0");
	}
	if(m==1) {
		for(int i=1; i<=n; i++) {
			if(s[i]) {
				sum++;
			}
		}
		for(int i=n-sum+1; i<=n; i++) {
			ans*=i;
			ans%=998244353;
		}
	} else {
		for(int i=n-m+1; i<=n; i++) {
			ans*=i;
			ans%=998244353;
		}
	}
	printf("%lld",ans);
	return 0;
}
//RP++
