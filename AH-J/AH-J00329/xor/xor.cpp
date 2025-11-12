#include <cstdio>
long long n,k,a[2000005],ans,x,b[1000005],f[1000005],flag1,flag2;
void update(long long id,long long x){
	for (long long i=id;i<=n;i+=i&(-i))
		a[i]^=x;
}
long long find(long long x){
	long long sum=0;
	for (long long i=x;i;i-=i&(-i))
		sum^=a[i];
	return sum;
}
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	scanf ("%lld%lld",&n,&k);
	for (long long i=1;i<=n;i++){
		scanf ("%lld",&f[i]);
		update(i,f[i]);
		if (f[i]!=1)
			flag1=1;
		if (f[i]!=1&&f[i]!=0)
			flag2=1;
	}
	if (!flag1){
		printf ("%lld",n/2);
		return 0;
	}
	if (!flag2){
		if (k==1){
			for (int i=1;i<n;i++){
				if (f[i]!=f[i+1])
					ans++,i++;
			}
			printf ("%lld",ans);
		}
		if (k==0){
			for (int i=1;i<n;i++){
				if (f[i]==f[i+1])
					ans++,i++;
			}
			printf ("%lld",ans);
		}
		return 0;
	}
	for (long long i=0;i<n;i++)
		for (long long j=1;j<=n-i;j++){
			while (b[j])
				j=b[j];
			if ((find(i+j)^find(j-1))==k){
				ans++;
				b[j]=i+j+1;
				update(j,f[j]);
				update(j,ans*1e4);
				update(i+j,f[i+j]);
				update(i+j,ans*1e5);
				j+=i;
			}
		}
	printf ("%lld",ans);
	return 0;
}

