#include<iostream>
using namespace std;
int a[5010];
const int M=998244353;
int qmi(int n){
	long long ans=1, mul=2;
	while(n){
		if(n&1)ans=ans*mul%M;
		mul=mul*mul%M;
		n>>=1;
	}
	return ans;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)scanf("%d", &a[i]);
	bool bo=1;
	for(int i=0;i<n;i++)if(a[i]!=1){
		bo=0;
		break;
	}
	if(bo)printf("%lld", (qmi(n)-(1ll*n*(n-1)/2+n+1)%M+M)%M);
	else{
		int ans=0;
		for(int i=0;i<(1<<n);i++){
			int sum1=0, sum2=0, maxx=0;
			for(int j=0;j<n;j++)if((i>>j)&1){
				sum1++;
				sum2+=a[j];
				maxx=max(maxx, a[j]);
			}
			if(sum2>maxx*2)ans=(ans+1)%M;
		}
		printf("%d", ans);
	}
	return 0;
}
