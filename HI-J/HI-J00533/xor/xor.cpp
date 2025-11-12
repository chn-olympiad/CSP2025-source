#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	bool f=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[1]){
			f=1;
		}
	}
	if(k==0&&f==0){
		n=n/2;
		printf("%d",n);
		return 0;
	}
	f=0;
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
		a[i]=-1;
		sum++;	
		}
	}
	int c=-1;
	for(int i=1;i<=n;i++){
	if(a[i]==-1){
		c=a[i];
	}
		if(a[i]!=-1&&c==-1){
			c=a[i];
		}else if(a[i]!=-1){
			c=a[i]^c;
				if(c==k){
					if(i!=n){
						sum++;
			c=a[i+1];	
					}else{
						sum++;
					}
	}
}	
	}
	printf("%lld",sum);
	return 0;
}
