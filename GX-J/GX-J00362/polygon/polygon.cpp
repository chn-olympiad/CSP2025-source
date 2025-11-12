#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int n,a[5500];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		int ma=0;
		for(int j=0;j<=i;j++){
			for(int k=i-j;k<=i;k++){
				if(ma>i*2){
					sum++;
					continue;
				}
				else{ma+=a[k];}
			}
		}
	}
	printf("%lld",sum%998244353);
	return 0;
}
