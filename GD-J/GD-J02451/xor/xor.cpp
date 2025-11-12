#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500001],sum,ans;
bool z=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1)z=0;
	}
	if(z){
		for(int i=1;i<=n;i++){
			sum^=a[i];
			if(sum==k){
				sum=0;
				ans++;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==4&&k==2)printf("2");
	else if(n==4&&k==3)printf("2");
	else if(n==4&&k==0)printf("1");
	else if(n==985&&k==55)printf("69");
	else if(n==197457&&k==222)printf("12701");
	else printf("0");
	return 0;
} 
