#include<bits/stdc++.h>
using namespace std;
const int N=5020,M=5e4+10;
const long long Q=998244353;
int n,a[N],f[M],ans;
bool t18=1;
long long ksm(long long n,int m){
	long long ret=1;
	while(m){
		if(m&1)ret=ret*n%Q;
		n=n*n%Q,m>>=1;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),t18&=(a[i]==1);
	if(t18){
		printf("%lld\n",((((ksm(2,n)-n*1ll*(n-1)/2)%Q+Q)%Q-n-1)%Q+Q)%Q);
		fclose(stdin),fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1),f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;i>=3&&j<M;j++)ans=(ans+f[j])%Q;
		for(int j=M-1;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%Q;
//		for(int j=0;j<M;j++){
//			if(f[j])printf("f(%d,%d)=%d\n",i,j,f[j]);
//		}
//		printf("\n");
	}
	printf("%d\n",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}