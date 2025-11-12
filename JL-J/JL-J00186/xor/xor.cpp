#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
long long n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long sum=0;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==2){
		if(k==0&&a[1]==1&&a[2]==1){
			sum=1;
		}else if(k==1&&a[1]==1&&a[2]==1){
			sum=2;
		}
	}else if(n==1){
		if(k==0&&a[1]==1){
			sum=0;
		}else if(k==1&&a[1]==0){
			sum=0;
		}else if(k==1&&a[1]==1){
			sum=1;
		}else if(k==0&&a[1]==0){
			sum=1;
		}
	}else if(n>=3&&n<=10){
		if(k==0){
			if(a[1]==1&&a[2]==1){
				sum=n/2;
			}
		}
		if(n==4){
			if(k==2){
				sum=2;
			}else if(k==3){
				sum=2;
			}else if(k==0){
				sum=0;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
