#include <bits/stdc++.h>
int a[200005];
long long b=0;
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1 or n==0){
		printf("0");
		return 0;
	}
	if(n==2){
		if(a[1]==0 or a[2]==0){
			if(k!=max(a[1],a[2])){
				printf("0");
				return 0;
			}else{
				printf("1");
				return 0;
			}
		}
	}
	if(n>2){
		int k1;
		if(k==0){
			for(int i=1;i<n-1;i++){
				k1=a[i];
				for(int j=i;j<n;j++){
					if(k1==a[j]){
						b++;
						i=j+1;
						break;
					}else{
						k1=1;
					} 
				}
			}
		}else if(k==1){
			for(int i=1;i<n-1;i++){
				k1=a[i];
				for(int j=i;j<n;j++){
					if(k1!=a[j]){
						b++;
						i=j+1;
						break;
					}else{
						k1=0;
					} 
				}
			}
		}
	}
	printf("%lld",b);
	return 0;
}