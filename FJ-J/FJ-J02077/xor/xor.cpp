/*4 2
2 1 0 3
*/
#include<stdio.h>
long long a[500005]={0},b[500005]={0},c[500005]={0};
int main(){
	//printf("%d",(1^0)^(0^3));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	/*long long a=1;
	for(int i=1;i<=20;i++){
		a*=2;
	}
	printf("%lld",a);*/
	//printf("%d",2^1);
	long long n,k;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//printf("%d %d\n",b[i-1],a[i]);
		b[i]=b[i-1]^a[i];
	}
	/*for(int i=1;i<=n;i++){
		printf("%d:%lld\n",i,b[i]);
	}*/
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			c[i]=i;
		}
		for(int j=i+1;j<=n;j++){
			if((b[i-1]^b[j])==k){
				//printf("%d %d %d\n",b[i-1]^b[j],i,j);
				c[i]=j;
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		printf("%d ",c[i]);
	}*/
	int ans=0,r=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			if(i>r){
				ans++;
				r=c[i];
			}else{
				if(c[i]<r){
					r=c[i];
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}