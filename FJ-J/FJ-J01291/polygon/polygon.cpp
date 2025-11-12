#include <bits/stdc++.h>
using namespace std;
int n=0,a[5005]={0},b[5005]={0};
long long _3(){
	long long num;
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){
				if(2*max(a[i1],max(a[i2],a[i3]))<a[i1]+a[i2]+a[i3]){
					num++;
					num=num%998244353;
				}
			}
		}
	}
	return num;
}
long long _4(){
	long long num;
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){	
				for(int i4=i3+1;i4<=n;i4++){
					if(2*max(a[i1],max(a[i2],max(a[i3],a[i4])))<a[i1]+a[i2]+a[i3]+a[i4]){
						num++;
						num=num%998244353;
					}
				}
			}
		}
	}
	return num;
}
long long _5(){
	long long num;
	for(int i1=1;i1<=n;i1++){
		for(int i2=i1+1;i2<=n;i2++){
			for(int i3=i2+1;i3<=n;i3++){	
				for(int i4=i3+1;i4<=n;i4++){
					for(int i5=i4+1;i5<=n;i5++){
						if(2*max(a[i1],max(a[i2],max(a[i3],max(a[i4],a[i5]))))<a[i1]+a[i2]+a[i3]+a[i4]+a[i5]){
							num++;
							num=num%998244353;
					}}
			}
		}
	}
}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n==3){
		if(a[3]<a[1]+a[2]){
			printf("1");
		}else {
			printf("0");
		}
	}else{
		printf("%lld",_3()+_4()+_5());
	}
	return 0;
}
