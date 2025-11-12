#include<cstdio>
int n,m;
long long s=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	if(m==n){puts("0");return 0;}
	for(long long i=1;i<=n;i++)s=s*i%998244353;
	printf("%lld\n",s);
	return 0;//The AFOer finally enjoys his last journey on OI.Goodbye,world!
}
