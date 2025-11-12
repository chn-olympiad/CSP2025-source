#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500010],t,u;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==1)t++;
		if(a[i]<2)u++;
	}
	if(t==n){
		printf("%lld",n);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(u==n){
		if(k==0){
			ll ma1=0,ma2=0;
			for(int i=1;i<=n;i++)
			if(a[i]==0)ma1++;
			for(int i=1;i<n;i++)
			if(a[i]==a[i+1])ma2++,i++;
			printf("%lld",max(ma1,ma2));
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else{
			ll ma1=0,ma2=0;
			for(int i=1;i<=n;i++)
			if(a[i]==1)ma1++;
			for(int i=1;i<n;i++)
			if(a[i]!=a[i+1])ma2++,i++;
			printf("%lld",max(ma1,ma2));
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}
	ll ma1=0,ma2=0;
	for(int i=1;i<=n;i++)
	if(a[i]==k)ma1++;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			ma2++;
			continue;
		}
		else{
			ll s=a[i];
			for(int j=i+1;j<=n;j++){
				if((s^a[j])==k){
					ma2++;
					i=j;
					break;
				}
				s^=a[j];
			}
		}
	}
	printf("%lld",max(ma1,ma2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
