#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	int n,a[500010];
	long long k;
	scanf("%d",&n);
	scanf("%lld",&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long sum=-1;
	for(int i=1;i<=n;i++){
		int ma=a[i];
		long long sun=0;
		for(int j=1;j<=i;j++){
			ma^=a[j];
			if(ma==k){
				sun++;
				i+=1;
			}
		}
		if(sun>sum){
			sum=sun;
		}
	}
	printf("%lld",sum);
	return 0;
}
