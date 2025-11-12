#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],b[500010];
int xo(int x,int y){
	x^=y;
	return x;
}
int bs(int n,int k,int a[]){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(i==1){
			for(int j=1;j<=n;j++){
				if(a[j]==k) sum++;
			}
		}
		for(int j=1;j<=n-i+1;j++){
			int num=a[j];
			for(int c=j+1;c<=j+i;c++){
				num=xo(num,a[c]);
			}
			if(num==k){
				sum++;
			}
		}
	}
	return sum;
}
int k_valuezero(int n,int a[]){
	long long sum=0;
	for(int i=2;i<=n;i+=2){
		for(int j=1;j<=n-i+1;j++){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	if(k==0){
		sort(b+1,b+n+1);
		if(b[1]==1&&b[n]==1){		
		    printf("%d",k_valuezero(n,a));
	    }else{
	    	printf("%d",bs(n,k,a));
		}
	}else{
		printf("%d",bs(n,k,a));
	}
	return 0;
}
