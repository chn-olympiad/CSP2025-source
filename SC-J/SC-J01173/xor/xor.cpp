#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int num=0,numa=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]) num++;
		if(a[i]==0) numa++;
	}
	if(n==num){
		if(k==1){
			printf("%d",n);
		}
		else if(k==0){
			printf("%d",n/2);
		}
	}
	else {
		if(k==1){
			printf("%d",num);
		}
		if(k==0){
			for(int i=1;i<=n;){
				int len=0;
				if(a[i]==1){
					len=0;
					for(;i<=n;i++){
						if(a[i]==1){
							len++;
						}
						else{
							numa+=len/2;
							break;
						}
					}
				}
				else{
					i++;
				}
			}
			printf("%d",numa);
		}
	}
	return 0;
}