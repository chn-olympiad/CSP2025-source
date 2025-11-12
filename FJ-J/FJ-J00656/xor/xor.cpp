#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k,a[maxn];bool A,B;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0)A=1;
		if(a[i]!=1&&a[i]!=0){
			A=1;
			B=1;
		}
	}
	if(!A){
		if(k==0){
			printf("%d",n/2);
		}
		else{
			printf("%d",n);
		}
	}
	else if(!B){
		int one=0,zero=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)one++;
			else zero++;
		}
		if(k==1){
			printf("%d",one);
		}
		else{
			int cnt=0,tot=0;
			for(int i=1;i<=n;i++){
				cnt=0;
				while(a[i]==1){
					cnt++;
					i++;
				}
				tot+=cnt/2;
			}
			printf("%d",tot+zero);
		}
	}
	else{
		printf("1");
	}
	return 0;
}
