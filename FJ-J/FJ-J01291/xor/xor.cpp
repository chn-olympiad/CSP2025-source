#include <bits/stdc++.h>
using namespace std;
int yihuo(int a,int b){
	if(a==b){
		return 0;
	}else if(a!=b){
		return 1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=0,k=0;
	int a[500005]={0};
	int judge=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0&&judge!=3){
			judge=2;
		}
		if(a[i]>=2){
			judge=3;
		}
	}
	
	if(judge==1){//数全为1，k=0 
		printf("%d",n/2); 
	}else if(judge==2){//数=0或1,k=0或1 
		if(k==0){
			int num=0;
			for(int i=1;i<n;i++){
				if(a[i]==a[i+1]){
					num++;
					i++;
				}
			}
			printf("%d",num);
		}else{
			int num=0;
			int b=0;
			for(int i=1;i<n;i++){
				if(a[i]!=a[i+1]){
					num++;
					i++;
					b=a[i+1];
				}else if(yihuo(b,a[i+1])){
					num++;
					i++;
					b=a[i+1];
				}else{
					b=yihuo(b,a[i+1]);
				}
			}
			printf("%d",num);
		}
	}
	
	return 0;
} 
